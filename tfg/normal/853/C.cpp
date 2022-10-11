#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>

typedef long long ll;

const int ms = 200200;

int c = 0;

class node;
node* get();

class node
{
public:
	node(int val = 0){sum = val; left = this; right = this;}
	node(node *a, node *b)
	{
		left = a;
		right = b;
		sum = a->sum + b->sum;
	}

	node* upd(int pos, int val)
	{
		return upd(0, ms, pos, val);
	}

	int qry(int l, int r)
	{
		return qry(0, ms, l, r); 
	}

private:
	node *left, *right;
	int sum;

	int qry(int l, int r, int i, int j)
	{
		int mid = (l + r) / 2;
		if(i <= l && r <= j)
			return sum;
		else if(r < i || j < l || sum == 0)
			return 0;
		else
			return left->qry(l, mid, i, j) + right->qry(mid + 1, r, i, j);
	}

	node* upd(int l, int r, int pos, int val)
	{
		int mid = (l + r) / 2;
		node &ans = *(get());
		if(l == r)
			ans = node(sum + val);
		else if(pos <= mid)
			ans = node(left->upd(l, mid, pos, val), right);
		else
			ans = node(left, right->upd(mid + 1, r, pos, val));
		return &ans;
	}
};

node buffer[20 * ms];
node* get()
{
	return &buffer[c++];
}

node* roots[ms];

int qry(int x1, int x2, int y1)
{
	int ans = 0;
	ans += roots[x2]->qry(0, y1);
	ans -= roots[x1 - 1]->qry(0, y1);
	//std::cout << "for (" << x1 << ", " << x2 << ", " << y1 << ", " << y2 << ") got " << ans << "\n";
	return ans;
}

ll pairs(ll x)
{
	//std::cout << "pairs of " << x << "\n";
	return x * (x - 1) / 2;
}

int main()
{
	roots[0] = get();
	int n, q;
	std::cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		int num;
		scanf("%i", &num);
		roots[i] = roots[i - 1]->upd(num, 1);
	}
	for(int i = n + 1; i < ms; i++)
		roots[i] = roots[i - 1];
	//std::cout << "print\n";
	for(int i = 0; i < q; i++)
	{
		int x1, x2, y1, y2;
		scanf("%i %i %i %i", &x1, &y1, &x2, &y2);
		ll ans = pairs(n);
		ans -= pairs(x1 - 1);
		ans -= pairs(n - x2);
		ans -= pairs(y1 - 1);
		ans -= pairs(n - y2);
		ans += pairs(qry(1, x1 - 1, y1 - 1));
		ans += pairs(x1 - 1 - qry(1, x1 - 1, y2));
		ans += pairs(qry(x2 + 1, n, y1 - 1));
		ans += pairs(n - x2 - qry(x2 + 1, n, y2));
		printf("%lli\n", ans);
	}
}