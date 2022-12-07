#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=105;
int n,a[N],m,b[N],f[N][N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),a[i]+=a[i-1];
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&b[i]),b[i]+=b[i-1];
	For(i,0,n) For(j,0,m) f[i][j]=0;
	f[0][0]=0;
	For(i,0,n) For(j,0,m){
		f[i][j+1]=max(f[i][j+1],max(f[i][j],a[i]+b[j+1]));
		f[i+1][j]=max(f[i+1][j],max(f[i][j],a[i+1]+b[j]));
	}
	cout<<f[n][m]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}