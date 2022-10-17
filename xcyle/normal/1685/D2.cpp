#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define maxn 205
using namespace std;
int T, n, p[maxn], col[maxn], numcol, vis[maxn], q[maxn], fa[maxn];
int cntl[maxn], cntr[maxn], tp[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int check(int l)
{
	ru(i, 1, l - 1) if(q[i] == q[l]) return 0;
	ru(i, 1, n) cntl[i] = cntr[i] = 0, tp[i] = 0, fa[i] = i;
	ru(i, 1, l - 1) 
	{
		int u = q[i], v = p[q[i + 1]]; tp[u]++, tp[v]++;
		if(u <= v) cntl[u]++, cntl[v]--;
		if(u >= v) cntr[v]++, cntr[u]--;
	}
	ru(i, 1, n) {cntl[i] += cntl[i - 1], cntr[i] += cntr[i - 1]; if(cntl[i] > 1 || cntr[i] > 1) return 0;}
	ru(i, 1, n - 1) if(cntl[i] || cntr[i]) 
	{
		int fu = find(col[i]), fv = find(col[i + 1]);
		if(fu == fv) return 0;
		fa[fu] = fv;
	}
	ru(i, 1, l - 1) 
	{
		int u = q[i], v = p[q[i + 1]];
		if(u <= v) cntl[v]++;
		if(u >= v) cntr[u]++;
	}
	ru(i, 1, n) if(cntl[i] && cntr[i] && !tp[i]) return 0;
	ru(i, 1, n - 1) if(tp[i] < 2 && tp[i + 1] < 2) fa[find(col[i])] = find(col[i + 1]); 
	ru(i, 1, numcol) if(find(i) != find(1)) return 0;
	return 1;
}
void solve()
{
	cin>>n;
	ru(i, 1, n) cin>>p[i], col[i] = 0;
	numcol = 0;
	ru(i, 1, n) if(!col[i])
	{
		col[i] = ++numcol;
		for (int j = p[i]; j != i; j = p[j]) col[j] = numcol;
	}
	ru(i, 1, n) for (q[i] = 1; q[i] <= n; q[i]++) if(check(i)) break; 
	ru(i, 1, n) cout<<q[i]<<" "; cout<<endl;
}
int main()
{
	cin>>T;
	while(T--) solve();
	return 0;
}