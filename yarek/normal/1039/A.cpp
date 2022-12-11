#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200001;
ll a[N];
ll b[N];
int x[N];
int must[N];
bool cant[N];

int main()
{
    int n;
    ll t;
    scanf("%d %lld", &n, &t);
    for(int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", x + i);
        if(x[i] < i)
        {
            puts("No");
            return 0;
        }
        must[i+1]++;
        must[x[i]+1]--;
        cant[x[i]+1] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        must[i] += must[i-1];
        if(must[i])
            b[i-1] = max(b[i-1], a[i] + t);
        b[i] = max(b[i-1] + 1, a[i] + t);
    }
    for(int i = 1; i <= n; i++)
        if(cant[i] && b[i-1] >= a[i] + t)
        {
            puts("No");
            return 0;
        }
    puts("Yes");
    for(int i = 1; i <= n; i++)
        printf("%lld ", b[i]);
    puts("");
}