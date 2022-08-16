#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,cys;
ll C[105][105],d[105][105][105],fac[105];

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); m=readint(); k=readint(); cys=readint();
	FastMod F=FastMod(cys);
	for(int i=0;i<=n;i++) C[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) C[i][j]=mod(C[i-1][j]+C[i-1][j-1]);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	for(int i=1;i<=n;i++) d[m][i][1]=fac[i];
	int num=k,all=k;
	for(int i=m-1;i>=1;i--){
		all+=(num+1)/2;
		num=(num+1)/2;
	}
	if(num>1) return printf("0\n"),0;
	if(all>n) return printf("0\n"),0;
	for(int i=m-1;i>=1;i--){
		for(int j=1;j<=n;j++){
			for(int l=0;l<=k;l++){
				if(j==1&&!l) d[i][j][l]=1;
				else d[i][j][l]=mod(2*d[i+1][j-1][l]);
				for(int t=1;t<=j-2;t++){
					for(int o=0;o<=l;o++)
						d[i][j][l]=F.reduce(d[i][j][l]+F.reduce(d[i+1][t][o]*d[i+1][j-t-1][l-o])*C[j-1][t]);
				}
			}
		}
	}
	printf("%lld\n",d[1][n][k]);
	return 0;
}