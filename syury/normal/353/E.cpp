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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e6 + 6;

int in[MAXN];
int n;
string s;
int p[MAXN];
int sz[MAXN];
int stk[MAXN];
int ptr = 0;

int find_set(int v){
	ret (v == p[v]) ? v : p[v] = find_set(p[v]);
}

void unite(int v, int u){
	v = find_set(v); u = find_set(u);
	if(v == u)ret;
	if(sz[v] > sz[u])swap(v, u);
	p[v] = u;
	sz[u] += sz[v];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(in);
	cin>>s;
	n = (int)s.length();
	F(i, 0, n){
		p[i] = i; sz[i] = 1;
		if(s[i] == '0')in[(i+1)%n]++; else in[i]++;
	}
	int ans = 0;
	F(i, 0, n)if(in[i] != 1){
		stk[ptr++] = i;
	}
	F(i, 0, ptr){
		int j = (i+1)%ptr;
		if((stk[j] - stk[i] + n)%n == 1)unite(stk[i], stk[j]);
	}
	F(i, 0, ptr){
		int s = sz[find_set(stk[i])];
		ans += s/2 + s%2;
		sz[find_set(stk[i])] = 0;
	}
	cout << ans;
	ret 0;
}