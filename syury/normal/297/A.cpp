#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i > (r); i--)
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
#define sz(x) (int)(x).size()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

int main(){
	sync;
	string s, t;
	cin >> s >> t;
	int l = 0, r = 0, ex = 0;
	I(c, s)if(c == '1'){l++;}
	I(c, t)if(c == '1'){r++;}
	ex = l%2;
	if(l + ex >= r)cout << "YES";
	else cout << "NO";
	return 0;
}