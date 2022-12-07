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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=105;
int n,m,f[N][N],s[N][N][N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		int x,l,r;
		scanf("%d",&x);
		For(j,1,x){
			int l,r;
			scanf("%d%d",&l,&r);
			For(k,l,r) ++s[l][r][k];
		}
	}
	For(i,1,m) For(j,i,m) For(k,i,j)
		s[i][j][k]+=s[i][j-1][k];
	Rep(i,m,1) For(j,i,m) For(k,i,j)
		s[i][j][k]+=s[i+1][j][k];
	memset(f,0,sizeof(f));
	Rep(i,m,1) For(j,i,m) For(k,i,j)
		f[i][j]=max(f[i][j],f[i][k-1]+f[k+1][j]+s[i][j][k]*s[i][j][k]);
	cout<<f[1][m]<<endl;
}