#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,ll> pil;


const ll linf=3e18;
const ll aval=1e15+10;
const int MOD=1e9+7;
const int N=1e6+10,M=1e3+5;

int n,pos[N][2];
ll k,a[M];
int getpos(ll val){
	if (k%val) return -1;
	if (val>N) return pos[k/val][1];
	return pos[val][0];
}
vector <ll> imp;
vector <ll> f;
vector <int> t[M];

template <class T>
bool minimize(T &x,T y){
	if (x>y) x=y;else return 0;
	return 1;
}
void prepare(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i*i<=k;i++) if (k%i==0){
		imp.push_back(i);
		if (i*i<k) imp.push_back(k/i);
	}
	sort(imp.begin(),imp.end());
	for(int i=0;i<imp.size();i++) if (imp[i]<N) pos[imp[i]][0]=i;
	else pos[k/imp[i]][1]=i;
}
vector <int> ansu;
void solve(){
	if (k==1){
		printf("1\n%d",min_element(a+1,a+n+1)-a);
		return;
	}
	int n1=imp.size();
	f.assign(n1,linf);
	f[0]=0;
	for(int i=1;i<=n;i++) t[i].resize(n1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<n1;j++) t[i][j]=j;
		for(int j=n1-1;j>=0;j--) if (f[j]!=linf){
			ll nval=__gcd(imp[n1-j-1],a[i])*imp[j];
			int idx=getpos(nval);
			if (minimize(f[idx],f[j]+aval+a[i])) t[i][idx]=j;
		}
	}
	if (f[n1-1]==linf){
		printf("-1");
		return;
	}
	for(int i=n,cur=n1-1;i>=1;i--){
		if (t[i][cur]!=cur) ansu.push_back(i);
		cur=t[i][cur];
	}
	printf("%d\n",ansu.size());
	reverse(ansu.begin(),ansu.end());
	for(auto i:ansu) printf("%d ",i);
}
int main(){
	prepare();
	solve();
}