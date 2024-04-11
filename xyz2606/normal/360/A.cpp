#include<cstring>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int n, Q, t[5001], l[5001], r[5001], d[5001], a[5001], b[5001];
bool flag;
int main()
{
    scanf("%d%d", &n, &Q);
    fill_n(a + 1, n, 1000000000);
    fill_n(b + 1, n, 0);
    for(int i = 1; i <= Q; i++)
    {
        scanf("%d%d%d%d", &t[i], &l[i], &r[i], &d[i]);
    }
    for(int i = 1; i <= Q; i++)
    {
        if(t[i] == 1)
        {
            for(int j = l[i]; j <= r[i]; j++) b[j] += d[i];
        }else
        {
            for(int j = l[i]; j <= r[i]; j++) a[j] = min(a[j], d[i] - b[j]);
        }
    }
    for(int i = 1; i <= n; i++) b[i] = a[i];
    //for(int i = 1; i <= n; i++) printf("%d%c", a[i], i == n?'\n':' ');
    flag = true;
    for(int i = 1; i <= Q; i++)
    {
        if(t[i] == 1)
        {
            for(int j = l[i]; j <= r[i]; j++) a[j] += d[i];
        }else
        {
            int res = 0x80000000;
            for(int j = l[i]; j <= r[i]; j++) res = max(res, a[j]);
            if(res != d[i]) 
            {
                flag = false;
                break;
            }
        }
    }
    if(flag == false)
    {
        printf("NO\n");
    }else
    {
        printf("YES\n");
        for(int i = 1; i <= n; i++) printf("%d%c", b[i], i == n?'\n':' ');
    }
    fclose(stdin);
    return 0;
}