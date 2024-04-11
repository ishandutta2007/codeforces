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
const int N=205;
int A,B,C;
int a1[N],a2[N],a3[N];
int f[N][N][N];
int main(){
	scanf("%d%d%d",&A,&B,&C);
	For(i,1,A) scanf("%d",&a1[i]);
	For(i,1,B) scanf("%d",&a2[i]);
	For(i,1,C) scanf("%d",&a3[i]);
	sort(a1+1,a1+A+1);
	sort(a2+1,a2+B+1);
	sort(a3+1,a3+C+1);
	For(i,0,A) For(j,0,B) For(k,0,C){
		f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a1[i+1]*a2[j+1]);
		f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a1[i+1]*a3[k+1]);
		f[i][j+1][k+1]=max(f[i][j+1][k+1],f[i][j][k]+a2[j+1]*a3[k+1]);
	}
	cout<<f[A][B][C];
}