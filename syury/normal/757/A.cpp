#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm afhdhn

map<char, int> cnt;
int n;
string s;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.length();
	F(i, 0, n){
		if(!cnt.count(s[i]))cnt[s[i]] = 1;
		else cnt[s[i]]++;
	}
	string t = "Bulbasaur";
	int ans = 1e9;
	I(c, t){
		int crr = cnt[c];
		if(c == 'u' || c == 'a')crr /= 2;
		ans = min(ans, crr);
	}
	cout << ans;
	ret 0;
}