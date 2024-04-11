#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
const int mo=998244353;
const int N=205;
int n,a[50];
ll h[N*2][N*2];
int f[3][3][N][N];
ll g[3][3][N][N];
int main(){
	scanf("%d",&n);
	For(i,0,25) scanf("%d",&a[i]);
	For(i,0,25) For(j,0,25)
		f[min(i,2)][min(j,2)][(i==0)+(j==0)][(i==1)+(j==1)]++;
	For(i,3,n){
		memset(g,0,sizeof(g));
		For(s1,0,(i+3)/2) For(s2,0,(i+3)/2)
			For(c1,0,2) For(c2,0,2) For(c3,0,2){
				int v=(c3==2?24:1)-(c1==c3);
				g[c2][c3][s1+(c3==0)][s2+(c3==1)]+=1ll*v*f[c1][c2][s1][s2];
			}
		For(s1,0,(i+3)/2) For(s2,0,(i+3)/2)
			For(c1,0,2) For(c2,0,2) f[c1][c2][s1][s2]=g[c1][c2][s1][s2]%mo;
	}
	For(s1,0,(n+3)/2) For(s2,0,(n+3)/2)
		For(c1,0,2) For(c2,0,2) h[s1][s2]+=f[c1][c2][s1][s2];
	Rep(s1,n,0) Rep(s2,n,0) h[s1][s2]=(h[s1][s2]+h[s1+1][s2])%mo;
	Rep(s1,n,0) Rep(s2,n,0) h[s1][s2]=(h[s1][s2]+h[s1][s2+1])%mo;
	int ans=h[0][0];
	//cout<<ans<<endl;
	For(i,0,25) ans=(ans+mo-h[a[i]+1][0])%mo;
	For(i,0,25) For(j,i+1,25) ans=(ans+h[a[i]+1][a[j]+1])%mo;
	cout<<ans<<endl;
}
/*
f[3][3][200][200] 
*/