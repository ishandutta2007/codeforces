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

int m, k, n;
bool good[102];
int L[102], R[102];

set<pair<int, int>, greater<pair<int, int> > > ls;
set<pair<int, int>, greater<pair<int, int> > > rs;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(good);
	scanf("%d%d", &m, &k);
	F(i, 0, k){
		int x; scanf("%d", &x);
		x--; good[x] = true;
	}
	scanf("%d", &n);
	F(i, 0, n){
		char c = getc(stdin);
		while(!isalpha(c))c = getc(stdin);
		while(isalpha(c))c = getc(stdin);
		int _k;
		scanf("%d", &_k);
		int l = 0, r;
		int d = 0;
		int _c = m - k;
		F(j, 0, _k){
			int x;
			scanf("%d", &x); x--;
			if(x >= 0 && good[x])l++;
			if(x < 0)d++;
			if(x >= 0 && !good[x])_c--;
		}
		if(d > _c){
			l += d - _c;
			d = _c;
		}
		r = min(l + d, k); r = min(r, _k);
		ls.ins(mk(l, i)); rs.ins(mk(r, i));
		L[i] = l; R[i] = r;
	}
	if(n == 1){printf("0"); ret 0;}
	F(i, 0, n){
		bool cg = false, cb = false;
		ls.era(mk(L[i], i));
		int b = ls.begin()->X;
		if(b <= R[i])cg = true;
		ls.ins(mk(L[i], i));
		rs.era(mk(R[i], i));
		b = rs.begin()->X;
		if(b > L[i])cb = true;
		rs.ins(mk(R[i], i));
		if(cg && cb){printf("2\n"); cont;}
		if(cg){printf("0\n"); cont;}
		printf("1\n");
	}
	ret 0;
}