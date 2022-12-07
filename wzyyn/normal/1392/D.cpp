#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
char s[N];
int f[N][2][3],n;
void solve(){
	scanf("%d%s",&n,s+1);
	int ans=1<<30;
	For(cc1,0,1) For(cc2,1,2){
		For(i,0,n+1) memset(f[i],30,sizeof(f[i]));
		f[0][cc1][cc2]=0;
		For(i,1,n) For(c1,0,1) For(c2,1,2) For(c,0,1){
			int nc1=c,nc2=(c==c1?c2+1:1);
			if (nc2>2) continue;
			f[i][nc1][nc2]=min(f[i][nc1][nc2],f[i-1][c1][c2]+(s[i]==(c?'L':'R')));
		}
		ans=min(ans,f[n][cc1][cc2]);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
RRL
RL
RLL
RRLL
*/