#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

LL n,m,k,x,y,x2,y2;
LL dx[N], dy[N];
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>x>>y>>x2>>y2>>n;
	x=x2-x, y=y2-y;
	dx[0] = dy[0] = 0;
	rep(i,1,n){
		cin>>s[i];
		dx[i] = dx[i-1]; dy[i] = dy[i-1];
		if(s[i]=='U')++dy[i];
		if(s[i]=='D')--dy[i];
		if(s[i]=='R')++dx[i];
		if(s[i]=='L')--dx[i];
	}
	LL l=0, r=3e14, ans=-1;
	while(l<=r){
		LL mid = l+r>>1;
		LL qq = mid/n, ww = mid%n;
		if(abs(qq*dx[n]+dx[ww]-x)+abs(qq*dy[n]+dy[ww]-y)<=mid){
			r = mid-1; ans = mid;
		}else l = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}