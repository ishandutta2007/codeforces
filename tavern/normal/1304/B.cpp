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
const int maxn = 105;

int n, m;
string s[maxn], t[maxn];
string pre, suf;
map<string, int> mp, mpr, isp;

int main(){
	cin >> n >> m;
	FOR(i, 0, n){
		cin >> s[i];
		t[i] = s[i];
		reverse(t[i].begin(), t[i].end());
		if(s[i] <= t[i])
			++mp[s[i]];
		else
			++mpr[t[i]];
		if(s[i] == t[i])
			isp[s[i]] = 1;
	}
	int res = 0;
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(isp[it -> fst])
			res += it -> snd / 2;
		else{
//			cout << it -> fst << " " << it -> snd << " " << mpr[it -> fst] << endl;
			res += min(it -> snd, mpr[it -> fst]) * 2;
			FOR(i, 0, min(it -> snd, mpr[it -> fst]))
				pre += it -> fst;
		}
	}
	suf = pre;
	reverse(suf.begin(), suf.end());
	FOR(i, 0, n) if(isp[s[i]]){
		if(mp[s[i]] & 1){
			cout << m * (res + 1) << endl;
			cout << pre << s[i] << suf << endl;
			return 0;
		}
	}
	cout << m * res << endl;
	cout << pre << suf << endl;
	return 0;
}