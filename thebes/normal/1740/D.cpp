#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
// const ll mod = 998244353;
typedef pair<double,double> pdd;
const int mn = 1e6+10;
const int SZ = 700;
const double pi = acos(-1.);
mt19937 rng(time(0));

int a[mn];
bool st[mn];
void solve() {
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++)st[i]=0;
	for(int i=0;i<k;i++){
		cin >> a[i];
	}
	int need = k;
	int used = 0;
	for(int i=0;i<k;i++){
		st[a[i]]=1;
		used++;
		while(st[need]){
			need--;
			used--;
		}
		//cerr << used << endl;
		if(used>n*m-4){
			printf("tidak\n"); 
			return;
		}
	}
	printf("ya\n");
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
	int tc=1;
	cin >> tc;
	for(int tcc=1;tcc<=tc;tcc++){
		//printf("Case #%d: ",tcc);
		solve();
	}
}