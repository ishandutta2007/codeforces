#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool v(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y') return true;
	return false;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;string s,t;cin>>s;t+=s[0];
	rep(i,sz(s)-1) if(!(v(s[i])&&v(s[i+1]))) t+=s[i+1];
	cout<<t;
	return 0;
}