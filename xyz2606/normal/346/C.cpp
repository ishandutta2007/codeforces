#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct rec
{
    int dp, b;
    rec(int _dp, int _b) {dp = _dp; b = _b;}
};
bool operator < (rec a, rec b)
{
    return a.dp > b.dp;
}
priority_queue<rec> hp;
int n, x[111111], a, b, range[1111111], dp[1111111];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + 1 + n);
    n = unique(x + 1, x + 1 + n)- x - 1;
    scanf("%d%d", &a, &b);
    for(int i = 0; i < a - b; i++)range[i] = i + 1 + b;
    for(int i = 1; i <= n; i++)
    {
        for(int j = (b + x[i] - 1) / x[i] * x[i]; j <= a; j += x[i])
            range[j - b] = max(range[j - b], j + x[i] - 1);
    }
    hp.push(rec(0, b));
    for(int i = b + 1; i <= a; i++)
    {
        while(range[hp.top().b - b] < i) hp.pop();
        dp[i - b] = hp.top().dp + 1;
        hp.push(rec(dp[i - b], i));
    }
    printf("%d\n", dp[a - b]);
    fclose(stdin);
    return 0;
}