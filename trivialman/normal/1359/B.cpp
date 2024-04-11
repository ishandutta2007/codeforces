#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1005;
mt19937 rng(time(0));

int T, n, m, x, y;
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	
	while(T--){
		scanf("%d%d%d%d\n",&n,&m,&x,&y);
		y = min(y, x<<1);
		int ans = 0;
		rep(i,1,n){
			scanf("%s\n", s+1);
			rep(j,1,m) if(s[j]=='.') {
				if(j<m && s[j+1]=='.') ans += y, j++;
				else ans += x;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}