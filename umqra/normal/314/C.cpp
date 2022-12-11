#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;
const int pow2 = (1 << 20);
int a[(int)1e5 + 100];

int add(int a, int b)
{                                               
	if (a + b < 0)
		return a + b + mod;
	if (a + b >= mod)
		return a + b - mod;
	return a + b;
}

int mult(int a, int b)
{
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

struct item
{
	int tree[pow2 * 2];
	void build()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = 0;
	}
	void addVal(int pos, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			tree[v] = add(tree[v], val);
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			addVal(pos, val, 2 * v, l, m);
		else
			addVal(pos, val, 2 * v + 1, m + 1, r);
		tree[v] = add(tree[2 * v], tree[2 * v + 1]);
	}    
	void setVal(int pos, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			tree[v] = val;                 
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			setVal(pos, val, 2 * v, l, m);
		else
			setVal(pos, val, 2 * v + 1, m + 1, r);
		tree[v] = add(tree[2 * v], tree[2 * v + 1]);
	}
	int getSum(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;
		int m = (l + r) / 2;
		return add(getSum(a, b, 2 * v, l, m), getSum(a, b, 2 * v + 1, m + 1, r));
	}
} tree;
                      
int lastNum[(int)1e6 + 100];
int val[(int)1e5 + 100];            
                                              
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int t = tree.getSum(0, a[i]);
		t = add(t, 1);
		t = mult(t, a[i]);    
		tree.setVal(a[i], t);                    
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)                 
	{
		int t = tree.getSum(a[i], a[i]); 	
		ans = add(ans, t);   
		tree.addVal(a[i], -t);
	}
	printf("%d", ans);
	

	return 0;
}