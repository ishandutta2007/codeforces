#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

ll ksm(ll x,ll k) {
	ll ret=1;
	while(k) {
		if(k&1)	ret=ret*x%mod;
		x=x*x%mod,k>>=1;
	}
	return ret;
}

const int Pn=1e7+5;
ll prime[Pn],pcnt,phi[Pn];
bool mark[Pn];
inline void Prime(ll n) {
	mark[1]=1;
	for(ll i=2;i<=n;i++) {
		if(!mark[i]) {
			prime[++pcnt]=i;
//			phi[i]=i-1;
		}
		for(ll j=1;j<=pcnt;j++) {
			ll k=i*prime[j];
			if(k>n)	break;
			mark[k]=1;
			if(i%prime[j]==0) {
//				phi[k]=phi[i]*prime[j];
				break;
			}
//			else	phi[k]=phi[i]*(prime[j]-1);
		}
	}
}

pair<ll,int> a[200005];
ll b[200005],vis[200005];

int father[200005];
int ff(int a){return a==father[a]?a:father[a]=ff(father[a]);}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("1.txt","r",stdin);
	int T=1;
	cin>>T;
	while(T--) {
		ll n,p; cin>>n>>p;
		for(int i=1;i<=n;i++)	cin>>b[i],a[i]={b[i],i},vis[i]=0;
		iota(father+1,father+n+1,1);
		sort(a+1,a+n+1);
		ll ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].first>=p)	break;
			for(int j=a[i].second+1;j<=n;j++) {
				if(b[j]%a[i].first)	break;
				int fa=ff(a[i].second),fb=ff(j);
				if(fa!=fb)
                {
                    father[fa]=fb;
                    ans+=a[i].first,cnt++;
                }
                else break;
			}
			for(int j=a[i].second-1;j;j--) {
				if(b[j]%a[i].first)	break;
				int fa=ff(a[i].second),fb=ff(j);
				if(fa!=fb)
                {
                    father[fa]=fb;
                    ans+=a[i].first,cnt++;
                }
                else break;
			}
		}
		ans+=(n-1-cnt)*p;
		cout<<ans<<"\n";
	}
}