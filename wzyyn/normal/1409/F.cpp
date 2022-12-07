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
int n,k;
char s[205],t[205];
int f[205][205][205];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s%s",s+1,t+1);
	memset(f,233,sizeof(f));
	f[0][0][0]=0;
	For(i,1,n) For(j,0,i) For(p,0,min(i,k))
		For(ch,'a','z'){
			int np=(ch==s[i]?p:p+1);
			int nj=(ch==t[1]?j+1:j);
			f[i][nj][np]=max(f[i][nj][np],f[i-1][j][p]+(ch==t[2]?j:0));
			//if (f[i-1][j][p]>=0&&ch=='a') cout<<i-1<<' '<<j<<' '<<p<<' '<<f[i-1][j][p]<<endl;
		}
	int ans=0;
	For(i,0,n) For(j,0,k)
		ans=max(ans,f[n][i][j]);
	cout<<ans<<endl;
}