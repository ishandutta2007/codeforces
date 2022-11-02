#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	int n;
	string s;
	cin >> s;
	n = s.length();
	F(i, 0, n){
		F(len, 1, n + 1){
			if(i + len > n)break;
			string t = s.substr(i, len);
			string h = t;
			reverse(all(h));
			if(t != h){ans = max(ans, len);}
		}
	}
	cout << ans;
	return 0;
}