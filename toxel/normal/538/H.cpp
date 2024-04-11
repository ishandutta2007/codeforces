#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int NN = N * 20;

int cnt = 0, cnt1 = 0, num = 0, t, T, n, m, code[N], l[N], r[N], type[NN];
bool vis[NN];
vector <int> vec1, vec, e[NN], re[NN];
map <int, int> Hash;

void push(int n)
{
	if (n >= 0 && n <= T)
		vec1.push_back(n);
}

void addedge(int u, int v)
{
	e[u].push_back(v);
	e[v ^ 1].push_back(u ^ 1);
	re[v].push_back(u);
	re[u ^ 1].push_back(v ^ 1);
}

void toposort(int i)
{
	vis[i] = true; 
	for (int j = 0, siz = e[i].size(); j < siz; j++)
		if (!vis[e[i][j]])
			toposort(e[i][j]);
	vec.push_back(i);
}

void dfs(int i, int c)
{
	vis[i] = true;
	type[i] = c;
	for (int j = 0, siz = re[i].size(); j < siz; j++)
		if (!vis[re[i][j]])
			dfs(re[i][j], c);
}

int main()
{
	scanf("%d%d", &t, &T);
	scanf("%d%d", &n, &m);
	push(0); push(t); push(T);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		push(l[i]); push(r[i]); push(t - r[i]); push(t - l[i]);// push(T - l[i]); push(T - r[i]);
	}
	sort(vec1.begin(), vec1.end());
	vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());
	num = vec1.size();
	for (int i = 0; i < 2 * num - 2; i += 2)
	{
		addedge(i, i + 2);
		addedge(i + 2 * num, i + 2 * num + 2);
	}
	addedge(2 * num - 2 ^ 1, 2 * num - 2);
	addedge(4 * num - 2 ^ 1, 4 * num - 2);
	int j = num - 1;
	for (int i = 0; i < num; i++)
	{
		while (j >= 0 && vec1[j] + vec1[i] >= t)
			j--;
		if (j < 0)
			break;
		addedge(2 * i, 2 * j + 2 * num ^ 1);
		addedge(2 * num + 2 * i, 2 * j ^ 1);
	}
	j = num - 1;
	for (int i = 0; i < num - 1; i++)
	{
		while (j >= 0 && vec1[j] + vec1[i + 1] > T)
			j--;
		if (j < 0)
			break;
		addedge(2 * i ^ 1, 2 * j + 2 * num);
		addedge(2 * num + 2 * i ^ 1, 2 * j);
	}
	for (int i = 0; i < num; i++)
		Hash[vec1[i]] = 2 * i;
	for (int i = 0; i < n; i++)
		if (Hash.count(r[i]))
		{
			addedge(4 * num + 2 * i, Hash[r[i]]);
			addedge(4 * num + 2 * i ^ 1, Hash[r[i]] + 2 * num);
		}
	for (int i = 0; i < n; i++)
	{
		if (l[i] > T)
			return printf("IMPOSSIBLE"), 0;
		if (Hash.count(l[i]) && Hash[l[i]])
		{
			addedge(4 * num + 2 * i, Hash[l[i]] - 2 ^ 1);
			addedge(4 * num + 2 * i ^ 1, Hash[l[i]] - 2 + 2 * num ^ 1);
		}
	}
	for (int i = 0, u, v; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		addedge(4 * num + 2 * u - 2, 4 * num + 2 * v - 2 ^ 1);
		addedge(4 * num + 2 * u - 2 ^ 1, 4 * num + 2 * v - 2);
	}
	for (int i = 0; i < 4 * num + 2 * n; i++)
		if (!vis[i])
			toposort(i);
	reverse(vec.begin(), vec.end());
	int c = 0;
	for (int i = 0; i < vec.size(); i++)
		vis[i] = false;
	for (int i = 0; i < vec.size(); i++)
		if (!vis[vec[i]])
			dfs(vec[i], ++c);
	//for (int i = 0; i < 4 * num + 2 * n; i += 2)
	//	cout << type[i] << ' ' << type[i ^ 1] << endl;
	for (int i = 0; i < 4 * num + 2 * n; i += 2)
		if (type[i] == type[i ^ 1])
			return printf("IMPOSSIBLE"), 0;
	printf("POSSIBLE\n");
	int n1, n2;
	for (int i = 0; i < 2 * num; i += 2)
		if (type[i] > type[i ^ 1])
		{
			n1 = vec1[i >> 1];
			break;
		}
	for (int i = 0; i < 2 * num; i += 2)
		if (type[i + 2 * num] > type[i + 2 * num ^ 1])
		{
			n2 = vec1[i >> 1];
			break;
		}
	printf("%d %d\n", n1, n2);
	for (int i = 0; i < n; i++)
		putchar(type[2 * i + 4 * num] > type[2 * i + 4 * num ^ 1] ? '1' : '2');
	putchar('\n');
	return 0;
}