#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100005];
int len,ans,ans2,sum[100005],sum2[100005];
int main()
{
    scanf("%s",s + 1);
    len = strlen(s + 1); ans = len;
    for (int i = 1; i <= len; i++)
    {
        sum[i] = sum[i - 1] + (s[i] >= 'a' && s[i] <= 'z');
    }
    for (int i = len; i >= 1; i--)
    {
        sum2[i] = sum2[i + 1] + (s[i] >= 'A' && s[i] <= 'Z');
    }
    for (int i = 0; i <= len; i++)
        ans = min(ans,sum[i]+sum2[i + 1]);
    printf("%d\n",ans);
    return 0;
}