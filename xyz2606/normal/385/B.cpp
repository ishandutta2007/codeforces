#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
char a[5555];
int n, lst, nxt[5555], ans, f[5555];
int main()
{
	scanf("%s", a);
	n = strlen(a);
	for(int i = 0; i + 3 < n; i++)
		f[i] = (a[i] == 'b' and a[i + 1] == 'e' and a[i + 2] == 'a' and a[i + 3] == 'r');
	lst = -1;
	for(int i = n - 1; i >= 0; i--)
	{	
		if(f[i]) lst = i;
		nxt[i] = lst;
	}
	ans = 0;
	for(int i = 0; i < n; i++) if(nxt[i] != -1) ans += n - nxt[i] - 3;
	printf("%d\n", ans);
	fclose(stdin);
	return 0;
}