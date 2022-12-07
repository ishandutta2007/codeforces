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
const int N=505;
int le[N][N];
int up[N][N];
ll f[N][N];
int main(){
	int n=1;
	ll bas=1,x,T;
	scanf("%lld",&x);
	for (T=x;x;n+=2){
		le[n+1][n]=le[n+2][n]=up[n][n+1]=up[n][n+2]=1;
		le[n-1][n+4]=le[n][n+4]=up[n+4][n-1]=up[n+4][n]=1;
		int rem=x%6; x/=6;
		if (x) le[n+3][n+2]=up[n+2][n+3]=1;
		else   up[n+3][n+2]=le[n+2][n+3]=1;
		if (rem<3) up[n+3][n+1]=1; else rem-=3;
		if (rem<3) le[n+1][n+3]=1; else rem-=3;
		if (!rem) up[n+3][n]=1; else --rem;
		if (!rem) le[n][n+3]=1; else --rem;
	}
	n+=1; f[1][1]=1;
	For(i,1,n) For(j,1,n){
		if (!le[i][j]) f[i][j]+=f[i][j-1];
		if (!up[i][j]) f[i][j]+=f[i-1][j];
	}
	//printf("%lld\n",f[n][n]);
	printf("%d %d\n",n,n);
	/*For(i,1,2*n-1){
		For(j,1,2*n-1)
			if (i%2==0&&j%2==0) putchar('*');
			else if (i%2==1&&j%2==1) putchar('.');
			else if (i%2==0&&j%2==1) putchar(up[i/2+1][j/2+1]?'*':'.');
			else if (i%2==1&&j%2==0) putchar(le[i/2+1][j/2+1]?'*':'.');
		puts("");
	}*/
	int sum=0;
	For(i,1,n) For(j,1,n){
		if (j!=1) sum+=le[i][j];
		if (i!=1) sum+=up[i][j];
	}
	printf("%d\n",sum);
	For(i,1,n) For(j,1,n){
		if (j!=1&&le[i][j]) printf("%d %d %d %d\n",i,j-1,i,j);
		if (i!=1&&up[i][j]) printf("%d %d %d %d\n",i-1,j,i,j);
	}
}
/*
....*.*****
....*.....*
....*****.*
...X......*
***.*.*.*.*
..*........
*.*.*.*.***
*.*........
*.*.*.*....
*.....*....
*****.*....
*/