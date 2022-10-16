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
const int maxn = 45;

int n, p;
ll ans = 0;
string s[maxn];

int main(){
	cin >> n >> p;
	FOR(i, 0, n){
		cin >> s[i];
	}
	ll rest = 0;
	for(int i = n - 1; i >= 0; --i){
		ans += p * rest;
		rest *= 2;
		if(s[i].size() > 4){
			ans += p / 2;
			rest += 1;
		}
	}
	cout << ans << endl;
	return 0;
}