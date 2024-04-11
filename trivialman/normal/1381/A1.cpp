#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 1e5+5;
mt19937 rng(time(0));

int n, T;
char a[N], b[N];
vector<int> ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n>>(a+1)>>(b+1);
		ans.clear();
		
		rrep(i,n,1){
			if(a[i]!=b[i]){
				if(i==1){
					ans.PB(1); break;
				}
				ans.PB(i), ans.PB(1), ans.PB(i);
			}
		}
		printf("%d", ans.size());
		for(auto x:ans) printf(" %d", x);
		printf("\n");
	}
	return 0;
}