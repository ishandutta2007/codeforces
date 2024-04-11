#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 18 | 5; 
const long long p1 = 1e9 + 7, p2 = 1e9 + 9, seed1 = 29, seed2 = 31;
int n, ct;
pair <long long, long long> pw[Maxn];
string str;
vector <int> Ve[4 * Maxn];
struct Tree
{
	int lson, rson;
	pair <long long, long long> Hash;
} tree[40 * Maxn];
pair <long long, long long> operator * (const pair <long long, long long> x, const pair <long long, long long> y)
{
	return make_pair(x.first * y.first % p1, x.second * y.second % p2);
}
pair <long long, long long> operator + (const pair <long long, long long> x, const pair <long long, long long> y)
{
	return make_pair((x.first + y.first) % p1, (x.second + y.second) % p2);
}
void build(int root, int lt, int rt)
{
	if (lt + 1 == rt)
		Ve[root].push_back(++ct), tree[ct].Hash = make_pair(str[lt] - 'a' + 1, str[lt] - 'a' + 1);
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid), build(root << 1 | 1, mid, rt);
		for (int i = 0; i < rt - lt; i++)
		{
			++ct;
			if (i >= rt - mid)
				tree[ct] = (Tree){Ve[root << 1 | 1][i - (rt - mid)], Ve[root << 1][i - (rt - mid)]};
			else tree[ct] = (Tree){Ve[root << 1][i], Ve[root << 1 | 1][i]};
			tree[ct].Hash = tree[tree[ct].lson].Hash * pw[mid - lt] + tree[tree[ct].rson].Hash;
			Ve[root].push_back(ct);
		}
	}
}
bool chkmin(int x, int y)
{
	if (!tree[x].lson)
		return tree[x].Hash < tree[y].Hash;
	else
	{
		if (tree[tree[x].lson].Hash != tree[tree[y].lson].Hash) return chkmin(tree[x].lson, tree[y].lson);
		return chkmin(tree[x].rson, tree[y].rson);
	}
}
void print(int x)
{
	if (tree[x].lson) print(tree[x].lson), print(tree[x].rson);
	else putchar(tree[x].Hash.first + 'a' - 1);
}
int main()
{
	scanf("%d", &n);
	cin >> str;
	pw[0].first = pw[0].second = 1;
	for (int i = 1; i < (1 << n); i++)
		pw[i].first = pw[i - 1].first * seed1 % p1, pw[i].second = pw[i - 1].second * seed2 % p2;
	build(1, 0, 1 << n);
	int mini = Ve[1][0];
	for (int i = 1; i < (1 << n); i++)
		mini = chkmin(mini, Ve[1][i]) ? mini : Ve[1][i];
	print(mini);
	return 0;
}