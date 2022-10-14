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

int n,k,h;

bool query(int x,int y,int z) {
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	char ret[3];
	scanf("%s",ret);
	return ret[0]=='Y'; 
}

bool leaf(int x) {
	int y=x;
	while (y==x) y=rnd(n)+1;
	rep(i,1,n+1) {
		if (i==x) continue;
		if (query(i,x,y)) return false;
	}
	return true;
}

VI vec;

bool diff(int x,int y) {
	vec.clear();
	rep(i,1,n+1) if (query(x,i,y)) vec.pb(i);
	return SZ(vec)==2*h-1;
}

int main() {
	scanf("%d%d",&n,&k);
	int pw=1,s=1; h=1;
	while (s<n) {
		pw*=k;
		h++;
		s+=pw;
	}
	int l1,l2;
	rep(i,0,20) {
		int x=rnd(n)+1;
		if (leaf(x)) { l1=x; break; }
	}
	rep(i,0,40) {
		int x=rnd(n)+1;
		if (leaf(x)&&diff(x,l1)) { l2=x; break; }
	}
	rep(i,0,SZ(vec)) {
		int cc=0;
		rep(j,0,SZ(vec)) {
			if (i==j) continue;
			if (query(l1,vec[i],vec[j])) cc++;
		}
		if (cc==h-1) {
			printf("! %d\n",vec[i]);
			fflush(stdout);
			return 0;
		}
	}
}