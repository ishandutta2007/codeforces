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
const int mo=1000000007;
const int N=1005;
double mt[15];
double tmp[N][N];
double S1[N][N],S2[N][N];
double S3[N][N],S4[N][N];
int L[N][N],R[N][N];
int U[N][N],DD[N][N];
int A[N][N],B[N][N];
int C[N][N],D[N][N];
char s[N][N];
int n;
int main(){
	scanf("%d",&n);
	mt[0]=-(1<<30);
	For(i,1,3) mt[i]=log(i);
	For(i,1,n){
		scanf("%s",s[i]+1);
		For(j,1,n) tmp[i][j]=mt[s[i][j]-'0'];
	}
	For(i,1,n) For(j,1,n){
		L[i][j]=(s[i][j]=='0'?0:L[i-1][j]+1);
		U[i][j]=(s[i][j]=='0'?0:U[i][j-1]+1);
		A[i][j]=(s[i][j]=='0'?0:A[i-1][j-1]+1);
		B[i][j]=(s[i][j]=='0'?0:B[i-1][j+1]+1);
	}
	Rep(i,n,1) Rep(j,n,1){
		R[i][j]=(s[i][j]=='0'?0:R[i+1][j]+1);
		DD[i][j]=(s[i][j]=='0'?0:DD[i][j+1]+1);
		C[i][j]=(s[i][j]=='0'?0:C[i+1][j-1]+1);
		D[i][j]=(s[i][j]=='0'?0:D[i+1][j+1]+1);
	}
	For(i,1,n) For(j,1,n) S1[i][j]=S1[i-1][j]+tmp[i][j];
	For(i,1,n) For(j,1,n) S2[i][j]=S2[i][j-1]+tmp[i][j];
	For(i,1,n) For(j,1,n) S3[i][j]=S3[i-1][j+1]+tmp[i][j];
	For(i,1,n) For(j,1,n) S4[i][j]=S4[i-1][j-1]+tmp[i][j];
	int tp=0,px,py,LL;
	double ansv=-1;
	For(i,1,n) For(j,1,n) if (s[i][j]!='0'){
		int L1=min(min(L[i][j],R[i][j]),min(U[i][j],DD[i][j]))-1;
		int L2=min(min(A[i][j],B[i][j]),min(C[i][j],D[i][j]))-1;
		double v1=S1[i+L1][j]-S1[i-L1-1][j]+S2[i][j+L1]-S2[i][j-L1-1]-tmp[i][j];
		double v2=S4[i+L2][j+L2]-S4[i-L2-1][j-L2-1]+S3[i+L2][j-L2]-S3[i-L2-1][j+L2+1]-tmp[i][j];
		//cout<<i<<' '<<j<<' '<<L1<<' '<<L2<<' '<<v1<<' '<<v2<<endl;
		if (v1>ansv) ansv=v1,px=i,py=j,tp=1,LL=L1;
		if (v2>ansv) ansv=v2,px=i,py=j,tp=2,LL=L2;
	}
	if (tp==0) puts("0");
	else{
		int ans=s[px][py]-'0';
		For(i,1,LL)
			if (tp==1){
				ans=1ll*ans*(s[px-i][py]-'0')%mo;
				ans=1ll*ans*(s[px+i][py]-'0')%mo;
				ans=1ll*ans*(s[px][py-i]-'0')%mo;
				ans=1ll*ans*(s[px][py+i]-'0')%mo;
			}
			else{
				ans=1ll*ans*(s[px-i][py-i]-'0')%mo;
				ans=1ll*ans*(s[px-i][py+i]-'0')%mo;
				ans=1ll*ans*(s[px+i][py-i]-'0')%mo;
				ans=1ll*ans*(s[px+i][py+i]-'0')%mo;
			}
		printf("%d\n",ans);
	}
}