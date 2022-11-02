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

const int MAXN = 2e5 + 5;

int n;
vector<int> a;
pair<int, int> nxt[MAXN][2];
bool ist[MAXN][2];
bool bck[MAXN][2];
lint val[MAXN][2];
list<pair<int, int> > in[MAXN][2];
queue<pair<int, int> > term;

void mark(){
	while(!term.empty()){
		int i = term.front().X, j = term.front().Y;
		term.pop();
		I(v, in[i][j]){
			int _i = v.X, _j = v.Y;
			if(!ist[_i][_j]){ist[_i][_j] = true; term.push(mk(_i, _j)); val[_i][_j] = a[_i] + val[i][j]; bck[_i][_j] = bck[i][j];}
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n - 1);
	F(i, 0, n - 1)scanf("%d", &a[i]);
	fi0(val); fi0(ist); fi0(bck);
	F(i, 0, n - 1){
		F(j, 0, 2){
			int _j = 1 - j;
			int _i = (j == 0) ? (i + a[i]) : (i - a[i]);
			if(_i + 2 > n){nxt[i][j] = mk(i, -1); val[i][j] = a[i]; ist[i][j] = true; term.push(mk(i, j));}
			else if(_i + 2 <= 0 || (_i + 2 == 1 && _j == 1)){nxt[i][j] = mk(i, -1); val[i][j] = a[i]; ist[i][j] = true; term.push(mk(i, j));}
			else if(_i != -1){nxt[i][j] = mk(_i, _j); in[_i][_j].pb(mk(i, j));}
			if(_i + 2 == 1 && _j == 1)bck[i][j] = true;
		}
	}
	mark();
	F(i, 1, n){
		lint ans = i;
		int f = i - 1;
		if(!ist[f][1]){printf("-1\n"); cont;}
		ans += val[f][1];
		if(bck[f][1])ans+=i;
		printf("%lld\n", ans);
	}
	ret 0;
}