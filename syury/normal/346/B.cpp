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

const int MAXN = 105;
const int inf = 1e-9;

int dp[MAXN][MAXN][MAXN];
int x[MAXN][MAXN][MAXN];
int y[MAXN][MAXN][MAXN];
int pl[MAXN][MAXN][MAXN];
string s1, s2, t;
int n, m, k;

void makep(int i, int j, int l, int _i, int _j, int _l){
	x[i][j][l] = _i;
	y[i][j][l] = _j;
	pl[i][j][l] = _l;
}

stack<char> str;

void restore(int i, int j, int l){
	//printf("restoring %d %d %d\n", i, j, l);
	if(i <= 0 || j == 0)ret;
	int _i = x[i][j][l], _j = y[i][j][l], _l = pl[i][j][l];
	if(_i == i - 1 && _j == j - 1)str.push(s1[i - 1]);
	restore(_i, _j, _l);
}

vector<int> pr;

void calcpr(){
	F(i, 0, k)
		F(l, 0, i + 1)
			if (t.substr(0,l) == t.substr(i-l+1, l))
				pr[i] = l;
}

int wh[MAXN][28];

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2 >> t;
	n = s1.length(); m = s2.length(); k = t.length(); pr.rs(k);
	calcpr();
	F(i, 0, k){
		F(c, 'A', 'Z' + 1){
			int j = c - 'A';
			int p = i;
			while(p >= 0 && (p + 1 == k || t[p + 1] != c)){
				p = pr[p] - 1;
			}
			wh[i][j] = p;
			//printf("wh[%d][%c] = %d\n", i, c, p);
		}
	}
	F(i, 0, n + 1)
		F(j, 0, m + 1)
			F(l, 0, k)
				x[i][j][l] = -10;
	F(i, 0, n + 1){
		dp[i][0][0] = 0;
		F(l, 1, k)dp[i][0][l] = -inf;
	}
	F(j, 0, m + 1){
		dp[0][j][0] = 0;
		F(l, 1, k)dp[0][j][l] = -inf;
	}
	F(i, 0, n){
		F(j, 0, m){
			F(l, 0, k){
				//printf("dp[%d][%d][%d] = %d\n", i, j, l, dp[i][j][l]);
				if(dp[i][j][l] > dp[i + 1][j][l]){dp[i + 1][j][l] = dp[i][j][l]; makep(i + 1, j, l, i, j, l);}
				if(dp[i][j][l] > dp[i][j + 1][l]){dp[i][j + 1][l] = dp[i][j][l]; makep(i, j + 1, l, i, j, l);}
				if(s1[i] != s2[j])cont;
				if(s1[i] == t[l]){
					if(l == k - 1)cont;
					if(dp[i + 1][j + 1][l + 1] < dp[i][j][l] + 1){dp[i + 1][j + 1][l + 1] = dp[i][j][l] + 1; makep(i + 1, j + 1, l + 1, i, j, l);}
					cont;
				}
				int _l = (l == 0) ? -1 : wh[l - 1][s1[i] - 'A'];
				if(_l == -1){if(s1[i] == t[0])_l = 1; else _l = 0;}
				else _l += 2;
				if(dp[i + 1][j + 1][_l] < dp[i][j][l] + 1){dp[i + 1][j + 1][_l] = dp[i][j][l] + 1; makep(i + 1, j + 1, _l, i, j, l);}
			}
		}
	}
	int ans = 0;
	int pos = 0, pi, pj;
	F(i, 0, n + 1)
		F(j, 0, m + 1)
			F(l, 0, k)
				if((i == n || j == m) && dp[i][j][l] > ans){ans = dp[i][j][l]; pos = l; pi = i; pj = j;}
	if(ans == 0){printf("0"); ret 0;}
	//printf("%d\n", ans);
	restore(pi, pj, pos);
	while(!str.empty()){
		putc(str.top(), stdout);
		str.pop();
	}
	ret 0;
}