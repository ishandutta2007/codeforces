#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 5e4 + 5;

int n;
string str;
string s[maxn];

inline bool cmp(string x, string y){
	return (x + y) < (y + x);
}

int main(){
	cin >> n;
	FOR(i, 0, n)
		cin >> s[i];
	sort(s, s + n, cmp);
//	FOR(i, 0, n)
//		cout << s[i] << endl;
	FOR(i, 0, n)
		str += s[i];
	cout << str << endl;
	return 0;
}