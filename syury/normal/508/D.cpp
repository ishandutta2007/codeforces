#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

const int CHR = 2 * ('z' - 'a' + 1) + 10;
const int maxn = 2e5 + 5 + CHR * CHR;

inline void fail(){
	cout << "NO";
	exit(0);
}

vector<int> out[maxn];
int ideg[maxn];
int n;
vector<string> s;
vector<int> seq;

inline int id(char c){
	if(isdigit(c))return c - '0';
	if(islower(c))return 10 + c - 'a';
	if(isupper(c))return 10 + 'z' - 'a' + 1 + c - 'A';
	assert(false);
	ret -1;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	s.resize(n);
	F(i, 0, n){
		cin >> s[i];
		int l = id(s[i][0]) * CHR + id(s[i][1]);
		int r = id(s[i][1]) * CHR + id(s[i][2]);
		out[l].pb(i + CHR*CHR);
		out[i + CHR*CHR].pb(r);
		++ideg[i + CHR*CHR];
		++ideg[r];
	}
	int v = -1;
	F(i, 0, n + CHR*CHR)if(ideg[i] < out[i].size()){if(out[i].size() - ideg[i] > 1)fail(); if(v != -1){fail();}v = i;}
	int ct = 0;
	F(i, 0, n + CHR*CHR)if(ideg[i] > out[i].size()){
		++ct;
		if(ct > 1)fail();
		if(ideg[i] - out[i].size() > 1)fail();
	}
	if(v == -1)F(i, 0, CHR*CHR)if(!out[i].empty()){v = i;}
	stack<int> st;
	st.push(v);
	while(!st.empty()){
		v = st.top();
		if(!out[v].empty()){
			int u = out[v].back();
			st.push(u);
			out[v].pop_back();
			cont;
		}
		if(v == st.top()){if(v >= CHR*CHR)seq.pb(v - CHR*CHR); st.pop();}
	}
	F(i, CHR*CHR, CHR*CHR + n)if(!out[i].empty()){cout << "NO"; ret 0;}
	reverse(all(seq));
	string ans = s[seq[0]];
	F(i, 1, (int)seq.size()){ans += s[seq[i]][2];}
	cout << "YES\n" << ans;
	return 0;
}