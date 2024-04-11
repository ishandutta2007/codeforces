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
int n, a[222222], s[222222];
long long ans;
int main()
{
    scanf("%d", &n);
    s[0] = 0;
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
        if(a[i] == 0) ans += s[i];
    }
    printf("%I64d\n", ans);
    fclose(stdin);
    return 0;
}