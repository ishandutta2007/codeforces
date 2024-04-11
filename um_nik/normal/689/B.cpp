#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = (int)1e7;
const int N = (int)1e6 + 100;
int n;
int a[N];
int dist[N];
int q[N];
int topQ;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
		dist[i] = INF;
	}
	dist[0] = 0;

	q[topQ++] = 0;
	for (int k = 0; k < topQ; k++)
	{
		int v = q[k];
		if (v > 0 && dist[v - 1] > dist[v] + 1)
		{
			dist[v - 1] = dist[v] + 1;
			q[topQ++] = v - 1;
		}
		if (v < n - 1 && dist[v + 1] > dist[v] + 1)
		{
			dist[v + 1] = dist[v] + 1;
			q[topQ++] = v + 1;
		}
		if (dist[a[v]] > dist[v] + 1)
		{
			dist[a[v]] = dist[v] + 1;
			q[topQ++] = a[v];
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");

	return 0;
}