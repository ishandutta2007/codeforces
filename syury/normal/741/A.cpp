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

int n;
int nxt[MAXN];
bool was[MAXN];
int len[MAXN];
int sz = 0;

int dfs(int v){
	was[v] = true;
	if(was[nxt[v]])ret nxt[v];
	else ret dfs(nxt[v]);
}

void calc(int v){
	was[v] = true; len[sz]++;
	if(!was[nxt[v]])calc(nxt[v]);
}

lint gcd(lint a, lint b){
	ret (a == 0) ? b : gcd(b % a, a);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n){
		scanf("%d", &nxt[i]); nxt[i]--;
	}
	F(i, 0, n){
		fi0(was);
		int x = dfs(i);
		if(x != i){printf("-1"); ret 0;}
	}
	fi0(was);
	F(i, 0, n){
		if(was[i])cont;
		calc(i); sz++;
	}
	lint lc = len[0];
	F(i, 1, sz){
		lint g = gcd(lc, len[i]);
		lc = lc * len[i] / g;
	}
	if(lc % 2 == 0)printf("%lld", lc/2); else printf("%lld", lc);
	ret 0;
}