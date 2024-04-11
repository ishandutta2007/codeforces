#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
int n,a[N],dp[10][N],cnt[N],F[N],I[N];

int sub(int a,int b) { return a-b>=0?a-b:a-b+mod; }
int mul(int a,int b) { return (ll)a*b%mod; }
int inv(int x) { return powmod(x,mod-2); }

int Ck(int n,int k) {
	if (n<k) return 0;
	return mul(F[n],mul(I[k],I[n-k]));
}

void calc() {
	F[0]=1;
	rep(i,1,N) F[i]=mul(F[i-1],i);
	I[N-1]=inv(F[N-1]);
	per(i,0,N-1) I[i]=mul(I[i+1],i+1);
}

int main() {
	calc();
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),cnt[a[i]]++;
	rep(i,1,N) for (int j=i+i;j<N;j+=i) cnt[i]+=cnt[j];
	rep(i,1,10) per(j,1,N) {
		dp[i][j]=Ck(cnt[j],i);
		//if (j<=10) printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
		for (int x=j+j;x<N;x+=j) dp[i][j]=sub(dp[i][j],dp[i][x]);
	}
	rep(i,1,10) {
		if (dp[i][1]>0) {
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
}