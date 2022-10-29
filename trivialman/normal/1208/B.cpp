#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, ans=N, a[N];
set<int> s;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,0,n){
		if(i){
			if(s.count(a[i])) break;
			s.insert(a[i]);
		}
		set<int> tmp = s;
		int j = n;
		for(;j>i;--j){
			if(tmp.count(a[j])) break;
			tmp.insert(a[j]);
		}
		ans = min(ans, j-i);
	}
	cout<<ans<<endl;
	return 0;
}