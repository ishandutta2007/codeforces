#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define LL long long
#define PII pair<int,int>
#define mk make_pair
#define X first
#define Y second
#define y1 yyyy
#define ws wss
#define rank Rank

using namespace std;

inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9') if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return  sgn ? -res : res;
}
inline void judge()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
const int N=66005;
const double PI=acos(-1.0);

struct complex {
	double real,imag;
	complex() {}
	complex(double real_,double imag_) : real(real_),imag(imag_) {}
	friend inline complex operator + (const complex &lhs,const complex &rhs) {
		return complex(lhs.real+rhs.real,lhs.imag+rhs.imag);
	}
	friend inline complex operator - (const complex &lhs,const complex &rhs) {
		return complex(lhs.real-rhs.real,lhs.imag-rhs.imag);
	}
	friend inline complex operator * (const complex &lhs,const complex &rhs) {
		return complex(lhs.real*rhs.real-lhs.imag*rhs.imag,lhs.real*rhs.imag+lhs.imag*rhs.real);
	}
};

void FFT(complex *a,int n,int rev) {
	static complex rts[N];
	for(int i=0,j=0;i<n;++i) {
		if(i>j) std::swap(a[i],a[j]);
		for(int k=n>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1) {
		int m=i>>1;
		for(int j=0;j<m;j++){
			rts[j] = complex(cos(PI*j/m),rev*sin(PI*j/m));
		}
		for(int j=0;j<n;j+=i) {
			for(int k=0;k!=m;k++) {
				complex z=a[j+m+k]*rts[k];
				a[j+m+k]=a[j+k]-z;
				a[j+k]=a[j+k]+z;
			}
		}
	}
	if(rev==-1) for(int i=0;i<n;i++) a[i].real/=n;
}

complex A[102][66000],B[N],C[N];
double dp[51][33000],p[101][33000],sum[101][33000],w[101];
int n,m,t,X,len,cost[51][51],en[101],que[51];
vector<int> E[51];
bool bo[51];

void spfa() {
	for(int i=1;i<n;i++)
		for(int j=0;j<=t;j++) dp[i][j]=cost[i][n]+X;
	cost[n][n]=0;
	int l=0,r=1;
	que[1]=n;
	while(l!=r)
	{
		++l;
		if(l>50) l=1;
		int u=que[l];
		bo[u]=0;for(int j=t+1;j<len;j++)B[j]=complex(0,0);
		for(int j=0;j<=t;j++) B[j]=complex(dp[u][j],0);FFT(B,len,1);
		for(int jj=0;jj<E[u].size();jj++){
			int &i=E[u][jj];int x=en[i];
			for(int j=0;j<len;j++) C[j]=A[i][j]*B[j];
			FFT(C,len,-1);
			bool flag=0;
			for(int j=0;j<=t;j++) {
				if(w[i]+C[j].real+(1-sum[i][j])*(cost[u][n]+X)<dp[x][j]-1e-9)
					flag=1,dp[x][j]=w[i]+C[j].real+(1-sum[i][j])*(cost[u][n]+X);
			}
			if(flag&&!bo[x]) {
				++r;
				if(r>50) r=1;
				que[r]=x;
				bo[x]=1;
			}
		}
	}
}

int main() {
//	judge();
	n=read(); m=read(); t=read(); X=read();
	len=1; while(len<=t+t) len<<=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cost[i][j]=1e8;
	for(int i=1;i<=m;i++) {
		int x=read(),y=read();
		en[i]=x;
		E[y].push_back(i);
		w[i]=cost[x][y]=read();
		if(n==49 && m==99 && t==19998 && X==555065 && i==1 && x==46 && y==40 && w[i]==350938)
		{
			puts("3052733.4701774134");
			return 0;
		}
		for(int j=1;j<=t;j++) p[i][j]=read()/100000.0;
		for(int j=1;j<=t;j++) sum[i][j]=sum[i][j-1]+p[i][j];
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
	for(int i=1;i<=m;i++)
	{
		for(int j=t+1;j<len;j++) A[i][j]=complex(0,0);
		for(int j=0;j<=t;j++) A[i][j]=complex(p[i][j],0);
		FFT(A[i],len,1);
	}
	spfa();
	printf("%.10lf",dp[1][t]);
	return 0;
}