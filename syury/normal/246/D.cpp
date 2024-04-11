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

vector<set<int> > col;
vector<int> c;
int n, m;
int minc = 1e9;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	col.rs((int)1e5 + 2);
	c.rs(n);
	F(i, 0, n){
		scanf("%d", &c[i]);
		minc = min(minc, c[i]);
	}
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		if(c[v] == c[u]){cont;}	
		col[c[v]].ins(c[u]);
		col[c[u]].ins(c[v]);
	}
	int ans = 0;
	int w = 0;
	F(i, 1, (int)col.size()){
		if(col[i].empty()){cont;}
		int sz = col[i].size();
		if(sz > ans){ans = sz; w = i;}
	}
	if(w == 0){w = minc;}
	printf("%d", w);
	ret 0;
}