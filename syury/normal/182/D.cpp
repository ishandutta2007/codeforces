#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
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
#define y1 adjf
#define tm afhdhn

void z(string & s, vector<int> & z){
	z[0] = 0;
	int l = 0, r = 0;
	F(i, 1, (int)s.length()){
		z[i] = 0;
		if(r >= i){z[i] = min(z[i - l], r - i + 1);}
		while(i + z[i] < (int)s.length() && s[z[i]] == s[i + z[i]])z[i]++;
		if(i + z[i] - 1 > r){
			l = i; r = i + z[i] - 1;
		}
	}
}

string s, t;
int n, m;
vector<int> zs, zt;
vector<char> ds, dt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> s >> t;
	n = s.length(); m = t.length();
	zs.rs(n); zt.rs(m);
	ds.rs(n); dt.rs(m);
	ds.asg(n, 0); dt.asg(m, 0);
	z(s, zs);
	z(t, zt);
	F(i, 0, n){
		ds[i] = true;
		for(int j = i + 1; j < n; j += i + 1)
			if(zs[j] < (i + 1)){ds[i] = false;}
	}
	F(i, 0, m){
		dt[i] = true;
		for(int j = i + 1; j < m; j += i + 1)
			if(zt[j] < (i + 1)){dt[i] = false;}
	}
	int ans = 0;
	F(i, 0, min(n, m)){
		if(s[i] != t[i]){brk;}
		if(ds[i] && dt[i])ans++;
	}
	printf("%d", ans);
	ret 0;
}