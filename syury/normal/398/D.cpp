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

const int MAXN = 3e5 + 5;

char myget(){
	char c = getc(stdin);
	while(!isalpha(c))c = getc(stdin);
	ret c;
}

set<int> gr[MAXN];
int st[MAXN];
int deg[MAXN];
int ans[MAXN];
int n, m, q;

void add_edge(int v, int u){
	if(deg[v] > deg[u])swap(v, u);
	gr[v].ins(u);
	deg[v]++;
	ans[u] += st[v];
}

void del_edge(int v, int u){
	if(!gr[v].count(u))swap(v, u);
	gr[v].era(u);
	ans[u] -= st[v];
	deg[v]--;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &q);
	fi0(st); fi0(ans); fi0(deg);
	int tmp;
	scanf("%d", &tmp);
	F(i, 0, tmp){
		int v;
		scanf("%d", &v); v--;
		st[v] = 1;
	}
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		add_edge(v, u);
	}
	F(i, 0, q){
		char c;
		int l, r;
		c = myget();
		if(c == 'A'){
			scanf("%d%d", &l, &r);
			l--; r--;
			add_edge(l, r);
		}
		if(c == 'D'){
			scanf("%d%d", &l, &r);
			l--; r--;
			del_edge(l, r);
		}
		if(c == 'O'){
			scanf("%d", &l);
			l--;
			st[l] = 1;
			I(u, gr[l])ans[u]++;
		}	
		if(c == 'F'){
			scanf("%d", &l);
			l--;
			st[l] = 0;
			I(u, gr[l])ans[u]--;
		}
		if(c == 'C'){
			scanf("%d", &l);
			l--;
			int res = ans[l];
			I(u, gr[l])res += st[u];
			printf("%d\n", res);
		}
	}
	ret 0;
}