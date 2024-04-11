#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=4005;
int n,a[N];
int f[N][N],g[N][N];
void solve(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%d",&a[i]);
	For(i,0,2*n) For(j,0,2*n) f[i][j]=g[i][j]=0;
	f[2*n][0]=1; a[2*n+1]=1<<30;
	Rep(i,2*n,0){
		int len=2*n-i;
		For(j,0,len) g[i][j]+=g[i+1][j];
		if (a[i]<a[i+1]){
			For(j,0,len) f[i][len-j]|=g[i][j];
			int val=0,p=i;
			for (;p>=1;p--){
				val=max(val,a[p]);
				if (val>a[i+1]) break;
			}
			For(j,0,len) if (f[i][j]){
				//cout<<i<<' '<<j<<endl;
				if (i) g[i-1][j]++;
				if (p) g[p-1][j]--;
			}
		}
	}
	puts(f[0][n]?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1
4
6 1 3 7 4 5 8 2
*/