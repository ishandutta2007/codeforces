/*input
2
0 10
0 10
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int diff[1000000],cnt[1000000],pref[1000000];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,N = 1000000;
	cin >> n;
	int l[n],r[n];
	set<int> su;
	REP(i,n){
		cin >> l[i] >> r[i];
		su.insert(l[i]);
		su.insert(r[i]);
		su.insert(l[i]-1);
	}
	mii com;
	int ind = 1;
	for(auto x:su) com[x] = ind++;
	REP(i,n){
		l[i] = com[l[i]];
		r[i] = com[r[i]];
	}	
	REP(i,n){
		diff[l[i]] ++;
		diff[r[i]+1] --;
	}
	cnt[0] = 0;
	pref[0] = 0;
	FOR(i,1,N){
		cnt[i] = cnt[i-1]+diff[i];
		pref[i]=pref[i-1];
		if(cnt[i]==1) pref[i]++;
	}
	REP(i,n){
		if(pref[r[i]]-pref[l[i]-1] == 0){
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1;
}