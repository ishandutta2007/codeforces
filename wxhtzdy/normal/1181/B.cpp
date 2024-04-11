#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=100050;
int n;
char s[N];
string ans;

void update(string s) {
	if (SZ(ans)<SZ(s)) return;
	if (SZ(ans)==SZ(s)) ans=min(ans,s);
	else ans=s;
}

string sum(string s1,string s2) {
	reverse(all(s1));
	reverse(all(s2));
	string sum="";
	int cc=0;
	rep(i,0,max(SZ(s1),SZ(s2))+2) {
		int d0=(SZ(s1)>i?(int)(s1[i]-'0'):0);
		int d1=(SZ(s2)>i?(int)(s2[i]-'0'):0);
		int ss=d0+d1+cc;
		cc=(ss/10);
		ss%=10;
		sum+=(char)(ss+'0');
	}
	while (SZ(sum)&&sum.back()=='0') sum.pop_back();
	if (sum.empty()) sum="0";
	reverse(all(sum));
	return sum;
}

void check(int x) {
	string s1="",s2="";
	rep(i,0,x) s1+=s[i];
	rep(i,x,n) s2+=s[i];
	update(sum(s1,s2));
}

int main() {
	scanf("%d",&n);
	scanf("%s",s);
	int l=n/2;
	int r=(n+1)/2;
	while (l>=0&&s[l]=='0') l--;
	while (r<n&&s[r]=='0') r++;
	ans=string(n+10,'9');
	if (l>0) check(l);
	if (r<n) check(r);
	rep(i,0,SZ(ans)) printf("%c",ans[i]);
}