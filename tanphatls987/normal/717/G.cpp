#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second

const int maxn = 550;
const int oo = 1e9;

typedef pair<int,int> pii;

struct edge
{
	int v, cap, f, c, doi;
	
	edge () {}
	
	edge (int _v, int _cap, int _f, int _c, int _doi)
	{
		v = _v; cap = _cap; f = _f;
		c = _c; doi = _doi;
	}
};

struct tnode
{
	int c;
	tnode* ke[26];
};

typedef tnode* pnode;

pnode root, nilT;

vector <edge> ke[maxn];
int n, k;
string S;
pii trace[maxn];
int d[maxn], dau[maxn];
deque<int> Q;

void add_edge(int u, int v, int cap, int c)
{
	edge a = edge(v, cap, 0, c, ke[v].size());
	edge b = edge(u, 0, 0, -c, ke[u].size());
	ke[u].pb(a);
	ke[v].pb(b);
}

void create_graph()
{
	for(int i=0; i<=n+1; i++)
		add_edge(i, i+1, k, 0);
	
	for(int i=1; i<=n; i++)
	{
		pnode p = root;
		int j = i;
		while (1)
		{
			//cout<<j<<endl;
			if (j > n)
				break;
			p = p -> ke[S[j - 1] - 'a'];
			if (p == nilT)
				break;
			if (p -> c != 0)
			{
				//add_edge(0, i, 1, -p->c);
				//add_edge(j+1, n+2, 1, 0);
				add_edge(i, j+1, 1, -p->c);
			}
			j++;
		}
	}
}

void create(pnode &p)
{
	p = new(tnode);
	for(int i=0; i<26; i++)
	{
		p->ke[i] = nilT;
	}
		
	p -> c = 0;
}

void build(pnode p, string T, int c, int l)
{
	if (l == T.size())
	{
		p -> c = c;
		return;
	}
	if (p -> ke[T[l] - 'a'] == nilT)
		create(p -> ke[T[l] - 'a']);
	build(p -> ke[T[l] - 'a'], T, c, l+1);
}

bool findPath()
{
	for(int i=0; i<=n; i++)
	{
		d[i] = oo;
		trace[i] = make_pair(-1, -1);
		dau[i] = 0;
	}
	d[0] = 0;
	while (!Q.empty()) Q.pop_front();
	Q.push_front(0);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop_front();
		dau[u] = 2;
		for(int j=0; j<ke[u].size(); j++)
		if (ke[u][j].f < ke[u][j].cap)
		{
			int v = ke[u][j].v;
			long long tmp = d[u] + ke[u][j].c;
			if (tmp < d[v])
			{
				d[v] = tmp;
				trace[v] = make_pair(u, j);
				if (dau[v] == 0)
					Q.push_back(v);
				else if (dau[v] == 2)
					Q.push_front(v);
				dau[v] = 1;
			}
		}
	}
	return (trace[n].fs > -1);
}

int enLarge(int &flow)
{
	int delta = oo;
	int v = n;
	while (v!=0)
	{
		int u = trace[v].fs;
		int j = trace[v].sc;
		delta = min(delta, ke[u][j].cap - ke[u][j].f);
		v = u;
	}
	
	v = n;
	int res = 0;
	while (v!=0)
	{
		int u = trace[v].fs;
		int j = trace[v].sc;
		int nj = ke[u][j].doi;
		ke[u][j].f += delta;
		ke[v][nj].f -= delta;
		res += (ke[u][j].c*delta);
		v = u;
	}
	flow += delta;
	return res;
}

void solve()
{
	n = n+2;
	int flow = 0;
	int res = 0;
	int s = 0;
	while (findPath())
	{
		int t = enLarge(flow);
		s += t;
		if (-s > res)
			res = -s;
	}
	printf("%d\n", res);
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("test.inp", "r", stdin);
	cin>>n;
	cin>>S;
	int m;
	cin>>m;
	nilT = new(tnode);
	create(root);
	//cout<<root->ke[0]<<endl;
	for(int i=1; i<=m; i++)
	{
		string T;
		int p;
		cin>>T>>p;
		build(root, T, p, 0);
	}
	cin>>k;
	create_graph();
	solve();
	return 0;
}