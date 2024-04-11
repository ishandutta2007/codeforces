#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
int v[N];
bool ok[N];
int n, k;

bool check(int x)
{
	queue<int> q;
	for(int i = k - 1; i < n; i++)
	{
		if(i == k - 1 || ok[i-k]) q.push(i-k);
		while(!q.empty() && v[i] - v[q.front()+1] > x)
			q.pop();
		ok[i] = !q.empty();
	}
	return ok[n-1];
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", v + i);
	}
	sort(v, v + n);
	int a = 0, b = 1e9+1, c;
	while(a < b)
	{
		c = (a + b) / 2;
		if(check(c)) b = c;
		else a = c + 1;
	}	
	printf("%d\n", a);
}