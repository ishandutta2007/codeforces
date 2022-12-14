#include <cmath> //
#include <cstdio> //
#include <cstdlib> //
#include <cstring> //
#include <algorithm> //STL 
#include <cmath>
#include <list> //STL 
#include <map> //STL 
#include <iostream>
#include <queue> //STL 
#include <set> //STL #
#include <stack> //STL 
#include <string> //
#include <vector> //STL 
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3fff3fff;

struct node
{
	int x, y;
	node(int a, int b) :x(a), y(b){};
};
vector<node> v;
int a[55][55];
int b[55][55];
int main()
{
    //freopen("in.txt","r",stdin);
	int n, m;
	bool flag = 1;
	cin >> n >> m;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j<m - 1; j++)
			if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1)
			{
		v.push_back(node(i, j));
		b[i][j] = 1, b[i + 1][j] = 1, b[i][j + 1] = 1, b[i + 1][j + 1] = 1;
			}


	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			if (a[i][j] != b[i][j])
			{
		cout << -1 << endl;
		return 0;
			}

	cout << v.size() << endl;
	for (int i = 0; i<v.size(); i++)
	{
		cout << v[i].x + 1 << " " << v[i].y + 1 << endl;
	}

	return 0;
}