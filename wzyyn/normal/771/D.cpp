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
const int N=105;
int n,S[N][3];
int q1[N],q2[N],q3[N];
int f[N][N][N][2];
char s[N];
int F(int i,int j,int k,int p){
	return max(0,S[p][0]-i)+max(0,S[p][1]-j)+max(0,S[p][2]-k);
}
void Fmin(int &x,int y){
	x>y?x=y:233;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	For(i,1,n){
		S[i][0]=S[i-1][0];
		S[i][1]=S[i-1][1];
		S[i][2]=S[i-1][2];
		if (s[i]=='V') q1[++*q1]=i,++S[i][0];
		else if (s[i]=='K') q2[++*q2]=i,++S[i][1];
		else q3[++*q3]=i,++S[i][2];
	}
	memset(f,60,sizeof(f));
	f[0][0][0][0]=0;
	For(i,0,*q1) For(j,0,*q2) For(k,0,*q3) For(fl,0,1){
		if (i!=*q1) Fmin(f[i+1][j][k][1],f[i][j][k][fl]+F(i+1,j,k,q1[i+1]));
		if (j!=*q2&&!fl) Fmin(f[i][j+1][k][0],f[i][j][k][fl]+F(i,j+1,k,q2[j+1]));
		if (k!=*q3) Fmin(f[i][j][k+1][0],f[i][j][k][fl]+F(i,j,k+1,q3[k+1]));
	}
	//cout<<f[3][0][0][1]<<endl;
	printf("%d\n",min(f[*q1][*q2][*q3][0],f[*q1][*q2][*q3][1]));
}