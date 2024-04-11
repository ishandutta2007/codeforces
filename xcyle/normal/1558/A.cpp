#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define maxn 200005
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
int a, b;
int t[maxn];
void solve()
{
	scanf("%d%d", &a, &b);
	for (int i = 0; i <= a + b; i++) t[i] = 0;
	int sum = a + b;
	for (int i = 0; i <= min((sum + 1) / 2, a); i++)
	{
		if(sum / 2 >= a - i && i + b - ((sum + 1) / 2 - i) >= 0) t[i + b - ((sum + 1) / 2 - i)] = 1;
	} 
	for (int i = 0; i <= min(sum / 2, a); i++)
	{
		if((sum + 1) / 2 >= a - i && i + b - (sum / 2 - i) >= 0) t[i + b - (sum / 2 - i)] = 1;
	} 
	int ans = 0;
	for (int i = 0; i <= a + b; i++) ans += t[i];
	printf("%d\n", ans);
	for (int i = 0; i <= a + b; i++) if(t[i]) printf("%d ", i);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}