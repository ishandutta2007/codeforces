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
int f[N][N*N],n;
int main(){
	scanf("%d",&n);
	memset(f,233,sizeof(f));
	f[0][0]=0;
	For(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);
		Rep(j,i-1,0) For(k,0,j*N){
			f[j+1][k+a]=max(f[j+1][k+a],f[j][k]+2*b);
			f[j][k]+=b;
		}
	}
	For(i,1,n){
		int v=0;
		For(j,0,i*N) v=max(v,min(2*j,f[i][j]));
		printf("%.10lf ",v/2.0);
	}
}