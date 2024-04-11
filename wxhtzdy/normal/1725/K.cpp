#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1000100;
int n,a[N],q,f[N],v[N],id[N];

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
void merge(int x,int y) { f[find(y)]=find(x); }

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&a[i]);
	rep(i,0,N) f[i]=i;
	map<int,int> ff;
	int cc=0;
	rep(i,0,n) {
		id[i]=cc++;
		v[id[i]]=a[i];
		if (ff.count(a[i])) merge(ff[a[i]],id[i]);
		else ff[a[i]]=id[i];
	}
	scanf("%d",&q);
	while (q--) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int k,w;
			scanf("%d%d",&k,&w),k--;
			id[k]=cc++;
			v[id[k]]=w;
			if (ff.count(w)) merge(ff[w],id[k]);
			else ff[w]=id[k];
		} else if (t==2) {
			int k;
			scanf("%d",&k),k--;
			printf("%d\n",v[find(id[k])]);
		} else {
			int l,r;
			scanf("%d%d",&l,&r);
			auto it=ff.lower_bound(l);
			while (it!=ff.end()&&it->first<=r) {
				int p;
				if (it->first<=(l+r)/2) p=l-1;
				else p=r+1;
				if (ff.count(p)) merge(ff[p],it->second);
				else v[it->second]=p,ff[p]=it->second;
				it=ff.erase(it);
			}
		}
	}

}