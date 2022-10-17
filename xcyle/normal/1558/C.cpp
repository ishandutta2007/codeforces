#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define maxn 3005
using namespace std;
int T;
inline int read()
{
	int w = 0, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar(); 
	}
	return w ? -x : x;
}
vector<int> ans;
int t[maxn], n, a[maxn];
void solve()
{
	scanf("%d", &n);
	ans.clear();
	for (int i = 1; i <= n; i++) t[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(i & 1) t[a[i]] = 1;
	}
	int flag = 1;
	for (int i = 1; i <= n; i += 2) flag &= t[i];
	if(!flag)
	{
		printf("-1\n");
		return;
	}
	for (int i = n; i >= 3; i -= 2)
	{
		for (int j = 1; j <= i; j++)
		{
			if(a[j] == i)
			{
				ans.push_back(j);
				for (int k = 1; k <= j / 2; k++) swap(a[k], a[j - k + 1]);
				break;
			}
		}
		int pos;
		for (int j = 1; j <= i; j++)
		{
			if(a[j] == i - 1) pos = j;
		}
		ans.push_back(pos - 1);
		for (int k = 1; k <= (pos - 1) / 2; k++) swap(a[k], a[pos - k]);
		ans.push_back(pos + 1);
		for (int k = 1; k <= (pos + 1) / 2; k++) swap(a[k], a[pos + 2 - k]);
		ans.push_back(3);
		swap(a[1], a[3]);
		ans.push_back(i);
		for (int k = 1; k <= i / 2; k++) swap(a[k], a[i + 1 - k]);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}