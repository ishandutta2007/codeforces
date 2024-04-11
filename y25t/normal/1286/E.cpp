#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll __int128_t
//#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define MASK ((1ll<<30)-1)
#define N 600005

inline void rd(ll &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void wr(ll x){
	if(!x)
		return;
	wr(x/10);
	putchar('0'+x%10);
}

int n;

int s[N];
ll w[N];

int nxt[N],f[N];

ll t[N<<2];
inline void ins(int p,int L,int R,int x,ll d){
	if(L==R){
		t[p]=d;
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid)
		ins(p<<1,L,mid,x,d);
	else
		ins(p<<1|1,mid+1,R,x,d);
	t[p]=std::min(t[p<<1],t[p<<1|1]);
}
inline ll mn(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return inf;
	if(l<=L&&R<=r)
		return t[p];
	int mid=(L+R)>>1;
	return std::min(mn(p<<1,L,mid,l,r),mn(p<<1|1,mid+1,R,l,r));
}

std::map<int,int> cnt;

ll sum,ans;

int main(){
	scanf("%d",&n);
	memset(t,0x3f,sizeof(t));
	for(int i=1,j=0;i<=n;i++){
		char c;
		scanf("%s",&c);
		rd(w[i]);
		s[i]=c=(c-'a'+ans)%26;
		w[i]^=(ans&MASK);
		ins(1,1,n,i,w[i]);
		if(i==1){
			ans=w[i];
			ans?wr(ans):(void)putchar('0');
			puts("");
			continue;
		}
		f[i-1]=s[j+1]==c?f[j]:j;
		for(int k=j;k>0;)
			if(s[k+1]==c)
				k=f[k];
			else{
				int val=mn(1,1,n,i-k,i-1);
				sum-=val;
				if(!--cnt[val])
					cnt.erase(val);
				k=nxt[k];
			}
		if(c==s[1]){
			sum+=w[i];
			cnt[w[i]]++;
		}
		int tmp=0;
		for(auto it=cnt.upper_bound(w[i]);it!=cnt.end();){
			tmp+=it->second;
			sum-=1ll*(it->first)*(it->second);
			auto _it=std::next(it);
			cnt.erase(it);
			it=_it;
		}
		cnt[w[i]]+=tmp;
		sum+=1ll*tmp*w[i];
		ans+=sum+mn(1,1,n,1,i);
		ans?wr(ans):(void)putchar('0');
		puts("");
		while(j&&s[j+1]!=c)
			j=nxt[j];
		if(i>1&&s[j+1]==c)
			j++;
		nxt[i]=j;
	}
}