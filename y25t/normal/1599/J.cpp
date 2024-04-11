#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define pii std::pair<ll,ll>
#define mp std::make_pair
#define fir first
#define sec second
#define ll long long
#define N 35

int _;

ll n;
ll a[1005];

struct hsh{

#define B 1000007
ll hd[B],_hd;
struct node{
	ll id,val;
	ll nxt;
}e[1<<22];
ll &operator [] (ll x){
	ll u=(x%B+B)%B;
	for(ll i=hd[u];i;i=e[i].nxt)
		if(e[i].id==x)
			return e[i].val;
	e[++_hd]=(node){x,-1,hd[u]};
	hd[u]=_hd;
	return e[_hd].val;
}
inline void cl(){
	memset(hd,0,sizeof(hd));
	_hd=0;
}

}vis,vis2;

#define num(x,y) (((y)-1)*N+(x))

ll cnt[1<<15],lg[1<<15];
ll sum[1<<15];
inline ll lb(ll x){
	return x&-x;
}

std::vector<ll> p,q,r;

ll b[1005];
pii ans[1005];
ll nn,cc[1000005];
ll Even[1005],Odd[1005],e,o;

int __;

int main(){
//	printf("%lld\n",((ll)&_-(ll)&__)>>20);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		if(!cc[a[i]])nn++;
		cc[a[i]]++;
	}
	if(nn<n){
		memset(cc,0,sizeof(cc));
		ll top;
		puts("YES"); 
		b[top=1]=0;
		for(ll i=1;i<=n;i++){
			if(!cc[a[i]]){
				b[++top]=a[i];
			}
			cc[a[i]]++;
		}
		for(ll i=1;i<=n;i++)printf("%lld ",b[i]);
		return 0;
	}
	if(n==2){
		puts("NO");
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]%2==0){
			Even[++e]=a[i];
		}else{
			Odd[++o]=a[i];
		} 
	}
	if(e>=3){
		ll top=3;
		ll vv=(Even[1]+Even[2]+Even[3])/2;
		b[1]=vv-Even[1];
		b[2]=vv-Even[2];
		b[3]=vv-Even[3];
		for(ll i=1;i<=o;i++)b[++top]=Odd[i]-b[1];
		for(ll i=4;i<=e;i++)b[++top]=Even[i]-b[1];
		puts("YES");
		for(ll i=1;i<=n;i++)printf("%lld ",b[i]);
		return 0;
	}
	if(e>=1&&n-e>=2){
		ll top=3;
		ll vv=(Odd[1]+Odd[2]+Even[1])/2;
		b[1]=vv-Odd[1];
		b[2]=vv-Odd[2];
		b[3]=vv-Even[1];
		for(ll i=3;i<=o;i++)b[++top]=Odd[i]-b[i];
		for(ll i=2;i<=e;i++)b[++top]=Even[i]-b[1];
		puts("YES");
		for(ll i=1;i<=n;i++)printf("%lld ",b[i]);
		return 0;
	}
	if(n-e==1&&e>=1){
		puts("NO");
		return 0;
	}
	ll nnn=n;
	n=std::min(n,22ll);
	lg[0]=-1;
	for(ll i=1;i<(1<<15);i++){
		cnt[i]=cnt[i>>1]+(i&1);
		lg[i]=lg[i>>1]+1;
	}
	for(ll i=1;i<(1<<n/2);i++)
		sum[i]=sum[i^lb(i)]+a[lg[lb(i)]+1];
	for(ll l=1;l<(1<<(n/2))&&!p.size();l++){
		if(vis2[num(cnt[l],sum[l])]!=-1){
			ll x=vis2[num(cnt[l],sum[l])],y=x&l,u=l^y,v=x^y;
			for(ll i=1;i<=n/2;i++)
				if((u>>(i-1))&1)
					p.push_back(i);
				else if((v>>(i-1))&1)
					q.push_back(i);
				else
					r.push_back(i);
			for(ll i=n/2+1;i<=n;i++)
				r.push_back(i);
			break;
		}
		vis2[num(cnt[l],sum[l])]=l;
		for(ll s=l;;s=(s-1)&l){
			ll t=l^s;
			if(cnt[t]<=cnt[s])
				vis[num(cnt[s]-cnt[t],sum[s]-sum[t])]=(ll)s<<n|(ll)t;
			if(!s)
				break;
		}
	}
	for(ll i=1;i<(1<<(n-n/2));i++)
		sum[i]=sum[i^lb(i)]+a[lg[lb(i)]+n/2+1];
	vis2.cl();
	for(ll l=1;l<(1<<n-n/2)&&!p.size();l++){
		if(vis2[num(cnt[l],sum[l])]!=-1){
			ll x=vis2[num(cnt[l],sum[l])],y=x&l,u=l^y,v=x^y;
			for(ll i=1;i<=n-n/2;i++)
				if((u>>(i-1))&1)
					p.push_back(i+n/2);
				else if((v>>(i-1))&1)
					q.push_back(i+n/2);
				else
					r.push_back(i+n/2);
			for(ll i=1;i<=n/2;i++)
				r.push_back(i);
			break;
		}
		vis2[num(cnt[l],sum[l])]=l;
		for(ll s=l;;s=(s-1)&l){
			ll t=l^s;
			if(cnt[t]<=cnt[s]){
				if(vis[num(cnt[s]-cnt[t],sum[s]-sum[t])]!=-1){
					auto x=vis[num(cnt[s]-cnt[t],sum[s]-sum[t])];
					ll u=x>>n,v=x&((1<<n)-1);
					for(ll i=1;i<=n/2;i++)
						if((u>>(i-1))&1)
							p.push_back(i);
						else if((v>>(i-1))&1)
							q.push_back(i);
						else
							r.push_back(i);
					for(ll i=1;i<=n-n/2;i++)
						if((s>>(i-1))&1)
							q.push_back(i+n/2);
						else if((t>>(i-1))&1)
							p.push_back(i+n/2);
						else
							r.push_back(i+n/2);
					break;
				}
			}
			if(!s)
				break;
		}
	}
	if(p.size()){
		ll k=p.size();
		b[1]=0;
		for(ll i=1;i<=k;i++){
			ll u=p.back(),v=q.back();
			p.pop_back(),q.pop_back();
			b[2*i]=a[u]-b[2*i-1];
			if(i!=k)
				b[2*i+1]=a[v]-b[2*i];
			ans[u]=mp(2*i-1,2*i);
			ans[v]=mp(2*i,i==k?1:2*i+1);
		}
		for(ll i=0;i<r.size();i++){
			b[2*k+1+i]=a[r[i]];
			ans[r[i]]=mp(2*k+1+i,1);
		}
		puts("YES");
		for(ll i=1;i<=n;i++)
			printf("%lld ",b[i]);
		for(ll i=n+1;i<=nnn;i++){
			printf("%lld ",a[i]-b[1]);
		}
		return 0;
	}
	else
		puts("No");
}