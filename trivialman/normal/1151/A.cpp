#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

LL n,m,k,x,y,x2,y2;
LL dx[N], dy[N];
char s[N];

int dist(char x, char y){
	int z = abs(y-x);
	return min(z,26-z);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>s[i];
	int ans = 1e8;
	rep(i,1,n-3){
		ans = min(ans, dist(s[i],'A')+dist(s[i+1],'C')+dist(s[i+2],'T')+dist(s[i+3],'G'));
	}
	cout<<ans<<endl;
	return 0;
}