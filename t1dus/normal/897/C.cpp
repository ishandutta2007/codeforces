/*input
5
0 69
1 194
1 139
0 47
1 66
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,k;
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?",s1 =  "What are you doing while sending \"",s2 = "\"? Are you busy? Will you send \"",s3 = "\"?";
int len[100005];

void precom(){
	len[0] = f0.length();
	FOR(i,1,100005){
		len[i] = 2*len[i-1]+68;
		len[i] = min(len[i],(ll)1000000000000000001);
	}
}

char solve(int n,int k){
	if(k >= len[n]) return '.';
	if(n == 0) return f0[k];
	if(k < s1.length()) return s1[k];
	k -= s1.length();
	if(k < len[n-1]) return solve(n-1,k);
	k -= len[n-1];
	if(k < s2.length()) return s2[k];
	k -= s2.length();
	if(k < len[n-1]) return solve(n-1,k);
	k -= len[n-1];
	return s3[k];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	precom();

	int t = 1;
	cin >> t;
	WL(t){
		cin >> n >> k;
		cout << solve(n,k-1);
	}
}