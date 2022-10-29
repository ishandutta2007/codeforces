#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 3e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,x,y,a[N];
vector<int> g[N];
bool v[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&x);
		a[x] = i;
	}
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		x = a[x], y = a[y];
		//cout<<x<<" "<<y<<endl;
		if(x<y) g[x].PB(y);
	}
	int cnt = 1, ans = 0;
	memset(v,false,sizeof v);
	v[n] = true;
	rrep(i,n-1,1){
		int t = cnt;
		for(auto x:g[i]){
			if(v[x]) --t;
		}
		if(t==0) ++ans;
		else v[i] = true, ++cnt;
	}
	cout<<ans<<endl;
	return 0;
}