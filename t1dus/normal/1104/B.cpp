#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

signed main(){
	string s;
	int n;
	cin >> s;
	n = s.length();
	int tot = 0;
	stack<char> st;
	REP(i,n){
		if(st.empty()) st.push(s[i]);
		else if(st.top() == s[i]){
			st.pop();
			tot ++;
		}
		else{
			st.push(s[i]);
		}
	}
	if(tot%2 == 0) cout << "No\n";
	else cout << "Yes\n";

}