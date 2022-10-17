#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 200005
using namespace std;
int T, n, a[maxn], t[maxn];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(t, 0, sizeof(t));
		scanf("%d", &n);
		int flag = 0;
		for (int i = 0; i < n; i++) 
		{
			scanf("%d", &a[i]);
			if(t[((i + a[i] + n) % n + n) % n]) flag = 1;
			t[((i + a[i]) % n + n) % n] = 1;
		}
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}