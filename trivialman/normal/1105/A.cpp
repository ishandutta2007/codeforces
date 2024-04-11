#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,a[1010];

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	int ans=1e9, ansi;
	rep(i,1,n)cin>>a[i];
	rep(t,1,100){
		int tot = 0;
		rep(i,1,n){
			if(a[i]>t) tot += (a[i]-t-1);
			if(a[i]<t) tot += (t-a[i]-1);
		}
		if(tot<ans){
			ans = tot;
			ansi = t;
		}
	}
	cout<<ansi<<" "<<ans<<endl;
	return 0;
}