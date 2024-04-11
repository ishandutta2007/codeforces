#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string in; cin >> in;
	vi s;
	vector <char> lol;
	int n = sz(in);
	s.pb(1); lol.pb(in[0]);
	repA(i,1,n-1){
		if(in[i] == in[i-1]){
		   	s.back()++;
		}else{
		   	s.pb(1);
			lol.pb(in[i]);
		}
	}
	int m = sz(s);
	if(m%2 == 1){
		int mm = m/2;
		bool possible = true;
		if(s[mm] < 2) possible = false;
		repA(i,1,mm){
			if(s[mm+i] + s[mm-i] < 3) possible = false;
			if(lol[mm+i] != lol[mm-i]) possible = false;
		}
		if(possible)
			cout << s[mm] + 1 << endl;
		else
			cout << 0 << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}