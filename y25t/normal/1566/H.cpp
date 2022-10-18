#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 1000005

std::mt19937 rng(114514);

int n,m;

int pr[N],_pr,mn[N];
bool np[N];
inline void si(int x){
	mn[1]=1;
	for(int i=2;i<=x;i++){
		if(!np[i])
			mn[i]=pr[++_pr]=i;
		for(int j=1;j<=_pr&&i*pr[j]<=x;j++){
			np[i*pr[j]]=1;
			mn[i*pr[j]]=pr[j];
			if(i%pr[j]==0)
				break;
		}
	}
}

bool in[N];

#define W 20
struct XB{
	int sz,rk,a[W],b[W],c[W];
	XB(){
		sz=rk=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	inline void ins(int x){
		sz++;
		int tmp=0,xx=x;
		for(int i=W-1;~i;i--)
			if((x>>i)&1){
				if(!b[i]){
					b[i]=x,c[i]=tmp|(1<<rk);
					a[rk++]=xx;
					return;
				}
				x^=b[i],tmp^=c[i];
			}
	}
	inline int sch(int x,int tp=0){
		int tmp=0;
		for(int i=W-1;~i;i--)
			if((x>>i)&1){
				if(!b[i])
					return inf;
				x^=b[i],tmp^=c[i];
			}
		int res=0;
		for(int i=0;i<rk;i++)
			if((tmp>>i)&1){
				res+=in[a[i]]?-1:1;
				if(tp)
					in[a[i]]^=1;
			}
		return res;
	}
}b[int(N*0.65)];

int c[N];

std::vector<int> p;
int id[N];

int f[N];

std::vector<int> s;

int main(){
	scanf("%d%d",&n,&m);
	si(n);
	for(int i=1;i<=n;i++){
		int x=i;
		c[i]=1;
		while(x>1){
			int tmp=mn[x];
			c[i]*=tmp;
			while(x%tmp==0)
				x/=tmp;
		}
		if(c[i]==i)
			p.push_back(i);
	}
	for(int i=0;i<p.size();i++)
		id[p[i]]=i;
	printf("%d ",p.size());
	for(auto x:p)
		printf("%d ",x);
	puts("");
	fflush(stdout);
	for(auto x:p)
		scanf("%d",&f[x]);
	for(int i=1;i<=n;i++)
		for(int j=i+i;j<=n;j+=i)
			if(c[j]==j)
				f[j]^=f[i];
	for(int i=n;i;i--)
		if(c[i]==i)
			for(int j=i+i;j<=n;j+=i)
				f[i]^=f[j];
	for(int i=1;i<=n;i++)
		b[id[c[i]]].ins(i);
	for(int i=1;i<=n;i++)
		if(b[id[c[i]]].sz!=b[id[c[i]]].rk)
			s.push_back(i);
	int mm=0;
	for(auto x:p)
		mm+=b[id[x]].sch(f[x],1);
	while(mm!=m){
		int x=s[rng()%s.size()],i=id[c[x]];
		int tmp=mm;
		tmp-=in[x];
		in[x]^=1;
		tmp+=in[x];
		tmp+=b[i].sch(x);
		if(std::make_pair(std::abs(tmp-m),rng())<std::make_pair(std::abs(mm-m),rng())){
			b[i].sch(x,1);
			mm=tmp;
		}
		else
			in[x]^=1;
	}
	for(int i=1;i<=n;i++)
		if(in[i])
			printf("%d ",i);
	puts("");
}