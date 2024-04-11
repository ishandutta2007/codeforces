#include <iostream>
#include <cstdio>
#define maxn 100005 
using namespace std;
int n, f[maxn][2], g[maxn][2], type;//0.01 
long long s[maxn], t[maxn], l, r;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &s[i], &t[i]);
		l = t[i] / 2 + 1, r = t[i], type = 0;//01 
		while(1)
		{
			if(l <= s[i] && s[i] <= r)
			{
				if(type != 0 && (r - s[i]) % 2 == type - 1) f[i][0] = 1;
				else f[i][0] = 0;
				break;
			}
			long long nxr = l - 1, nxl = nxr / 2 + 1;
			int nxt;
			if(type != 0)
			{
				if(r % 2 == type - 1) nxt = 0;	
				else nxt = (type + (r - nxr) % 2 - 1) % 2 + 1;
			}
			else nxt = 1;
			l = nxl, r = nxr, type = nxt;
		}
		l = t[i] / 2 + 1, r = t[i], type = 1;//012 
		while(1)
		{
			if(l <= s[i] && s[i] <= r)
			{
				if(type != 0 && (r - s[i]) % 2 == type - 1) f[i][1] = 1;
				else f[i][1] = 0;
				break;
			}
			long long nxr = l - 1, nxl = nxr / 2 + 1;
			int nxt;
			if(type != 0)
			{
				if(r % 2 == type - 1) nxt = 0;	
				else nxt = (type + (r - nxr) % 2 - 1) % 2 + 1;
			}
			else nxt = 1;
			l = nxl, r = nxr, type = nxt;
		}
	}
	for (int i = 1; i <= n; i++)
	{
//		printf("%d %d\n", f[i][0], f[i][1]);
	}
	int now = 1;
	for (int i = n; i >= 1; i--) now = f[i][now];
	printf("%d ", 1 - now);
	now = 0;
	for (int i = n; i >= 1; i--) now = f[i][now];
	printf("%d", 1 - now);
	return 0; 
}