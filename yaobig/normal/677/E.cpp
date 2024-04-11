#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5][maxn+5];
int a[maxn+5][maxn+5];

int a2,a3;
bool mark;
int pre[4][maxn+5][maxn+5];
int cnt2[2][maxn+5][maxn+5],cnt3[2][maxn+5][maxn+5];

void solve(int n)
{
	rep(i,1,n) pre[0][i][0]=0;
	rep(i,1,n) pre[1][i][n+1]=n+1;
	rep(i,1,n) pre[2][0][i]=0;
	rep(i,1,n) pre[3][n+1][i]=n+1;
	rep(i,1,n) rep(j,1,n) pre[0][i][j]=a[i][j]==0?j:pre[0][i][j-1];
	rep(i,1,n) per(j,1,n) pre[1][i][j]=a[i][j]==0?j:pre[1][i][j+1];
	rep(i,1,n) rep(j,1,n) pre[2][i][j]=a[i][j]==0?i:pre[2][i-1][j];
	per(i,1,n) rep(j,1,n) pre[3][i][j]=a[i][j]==0?i:pre[3][i+1][j];
	rep(i,1,n) rep(j,1,n) 
	{
		cnt2[0][i][j]=cnt2[0][i][j-1]+(a[i][j]==2);
		cnt2[1][i][j]=cnt2[1][i-1][j]+(a[i][j]==2);
		cnt3[0][i][j]=cnt3[0][i][j-1]+(a[i][j]==3);
		cnt3[1][i][j]=cnt3[1][i-1][j]+(a[i][j]==3);
	}
	rep(i,1,n) rep(j,1,n) if(a[i][j])
	{
		int len=inf;
		len=min(len,j-pre[0][i][j]);
		len=min(len,pre[1][i][j]-j);
		len=min(len,i-pre[2][i][j]);
		len=min(len,pre[3][i][j]-i);
		int l=j-len+1,r=j+len-1,u=i-len+1,d=i+len-1;
		int c2=cnt2[0][i][r]-cnt2[0][i][l-1]+cnt2[1][d][j]-cnt2[1][u-1][j]-(a[i][j]==2);
		int c3=cnt3[0][i][r]-cnt3[0][i][l-1]+cnt3[1][d][j]-cnt3[1][u-1][j]-(a[i][j]==3);
		int d2=c2-a2,d3=c3-a3;
		//printf("?? %d %d\n",c2,c3);
		if(d2+log2(3)*d3>=0) a2=c2,a3=c3,mark=1;
	}
}

ll qp(ll a,int k)
{
	ll res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

int main()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,n) a[i][j]=s[i][j]-'0';
	solve(n);
	int h=(n+1)/2;
	rep(i,1,n) rep(j,1,n) a[i][j]=0;
	rep(i,1,n) rep(j,1,n) if((i+j)%2==0) a[(i+j)/2][h+(j-i)/2]=s[i][j]-'0';
	solve(n);
	rep(i,1,n) rep(j,1,n) a[i][j]=0;
	rep(i,1,n) rep(j,1,n) if((i+j)%2==1) a[(i+j)/2][h+(j-i+1)/2]=s[i][j]-'0';
	solve(n);
	if(mark) printf("%I64d\n",qp(2,a2)*qp(3,a3)%mod);
	else puts("0");
	return 0;
}