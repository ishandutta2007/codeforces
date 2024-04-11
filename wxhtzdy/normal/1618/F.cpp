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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

ll x,y;
string s="",t="";
bool ok=0;
string cist(string ss) {
	int pos=0;
	while (ss[pos]=='0') pos++;
	string tt="";
	rep(i,pos,SZ(ss)) tt+=ss[i];
	return tt;
}
unordered_map<string,bool> was;
void check(string ss,int cc,bool ch) {
	if (was[ss]) return;
	was[ss]=1;
	//cerr<<ss<<" "<<cc<<endl;
	if (SZ(ss)>228) return;
	if (SZ(ss)==SZ(t)) {
		if (ss==t) ok=1;
		//return;
	}
	if (cc<=30) {
		string tt=ss+'0';
		reverse(all(tt));
		check(cist(tt),cc+1,true);
	}
	string tt=ss+'1';
	reverse(all(tt));
	check(cist(tt),cc,true);
}
int main() {
	scanf("%lld%lld",&x,&y);
	while (x>0) {
		s+=(char)(x%2+'0');
		x/=2;
	}
	reverse(all(s));
	while (y>0) {
		t+=(char)(y%2+'0');
		y/=2;
	}
	reverse(all(t));
	//cerr<<t<<endl;
	check(s,0,false);
	puts(ok?"YES":"NO");
}