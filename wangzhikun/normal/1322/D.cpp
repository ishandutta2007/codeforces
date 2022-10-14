#include <bits/stdc++.h>
using namespace std;
#define N 4040
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
int n,m,l[N],c[N],r[N];
int d[N][N] = {0},ans = 0;
int main() {
	cin>>n>>m;
	rep(i,1,n)cin>>l[i];
	rep(i,1,n)cin>>c[i];
	rep(i,1,n+m)cin>>r[i];
	rep(i,1,n+m)fill(d[i]+1,d[i]+N,-1e9);
	for(int i=n;i>=1;i--){
		for(int j=n-1;j>=0;j--)
			d[l[i]][j+1] = max(d[l[i]][j+1],d[l[i]][j]+r[l[i]]-c[i]);
		for(int j=l[i],h = n;j<m+n;j++,h/=2)
			rep(k,0,h)
				d[j+1][k/2] = max(d[j+1][k/2],d[j][k]+r[j+1]*(k/2));
	}
	rep(i,1,n+m)ans = max(ans,d[i][1]);
	cout<<ans<<endl;
	return 0;
}