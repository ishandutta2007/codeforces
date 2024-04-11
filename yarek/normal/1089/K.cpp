#include <bits/stdc++.h>
using namespace std;

// #define cerr if(0)cerr

typedef long long LL;
typedef pair < int, int > PII;

const int N = 2e6 + 7;
const int MAX = 1 << 21;

LL tree[2 * MAX], lazy[2 * MAX];

void propagate(int node, int l, int r)
{
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(l != r) 
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int a, int b, LL val, int node = 1, int l = 0, int r = MAX - 1)
{
	propagate(node, l, r);
	if(b < l || r < a) return;
	if(a <= l && r <= b)
	{
		lazy[node] += val;
		propagate(node, l, r);
	}
	else
	{
		update(a, b, val, 2 * node, l, (l + r) / 2);
		update(a, b, val, 2 * node + 1, (l + r) / 2 + 1, r);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

const LL INF = 1e18;
vector < pair < int, PII > > vec;

LL query(int a, int b, int node = 1, int l = 0, int r = MAX - 1)
{
	if(node == 1) vec.clear();
	//cerr << node << " " << l << " " << r << " := " << tree[node] << "\n";
	propagate(node, l, r);
	if(b < l || r < a) return INF;
	if(a <= l && r <= b)
	{
		vec.push_back({node, {l, r}});
	//	cerr << node << " " << l << " " << r << "\n";
		return tree[node];
	}

	LL l1 = query(a, b, 2 * node, l, (l + r) / 2);
	LL l2 = query(a, b, 2 * node + 1, (l + r) / 2 + 1, r);
	return min(l1, l2);
}

int cnt;
int T[N], D[N];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(int i = 0; i < MAX; i++)
		tree[MAX + i] = -i;
	for(int i = MAX - 1; i; i--)
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	
	int q; cin >> q;
	while(q--)
	{
		++cnt;
		char type; LL t;
		cin >> type >> t;
		if(type == '+')
		{
			LL d; cin >> d;
			T[cnt] = t;
			D[cnt] = d;
			update(t, MAX - 1, d);
		}
		else if(type == '-')
		{
			update(T[t], MAX - 1, -D[t]);
		}
		else
		{
			LL mn = query(0, t - 1);
			cout << query(t, t) - mn + 1 << "\n";
			continue;
			LL ans = query(t, MAX - 1);
			cerr << mn << " " << ans << "\n";
			LL when = -1;
			if(ans >= mn)
			{
				/* ... */
				when = MAX + ans - mn;
			}
			else
			{
				for(auto p: vec)
				{
					int node = p.first, l = p.second.first, r = p.second.second;
					cerr << node << " " << l << " " << r << " -> " << tree[node] << "\n";
					
					if(tree[node] < mn)
					{
						while(l < r)
						{
							int m = (l + r) / 2;
							propagate(2 * node, l, m);
							propagate(2 * node + 1, m + 1, r);
							if(tree[2 * node] < mn)
							{
								r = m;	
								node = 2 * node;
							}
							else
							{
								l = m + 1;
								node = 2 * node + 1;
							}
						}	
						when = l;
						break;
					}	
				}
			}
			cout << when - t << "\n";
		}	
	}
	
	return 0;
}