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
const ll mod=1000000009;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=100500;
char s[N];
int suc[N];

int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	int cc[2]={0,0};
	per(i,1,n+1) {
		if (s[i]=='1'&&cc[0]==cc[1]) cc[0]++,suc[i]=1;
		cc[s[i]-'0']++;
	}
	rep(i,1,n+1) {
		if (!suc[i]) printf("%c",s[i]);
		else printf("0");
	}
}