#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 300001;
int x[N];
int y[N];
ll ans[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> ind;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", x + i, y + i);
        ind.push_back(i);
    }
    sort(ind.begin(), ind.end(), [](int a, int b) { return x[a] - y[a] < x[b] - y[b]; });
    ll sum = 0;
    int c = 0;
    for(int i: ind)
    {
        ans[i] += sum + (ll)c * y[i];
        sum += x[i];
        c++;
    }
    sum = 0;
    c = 0;
    reverse(ind.begin(), ind.end());
    for(int i: ind)
    {
        ans[i] += sum + (ll)c * x[i];
        sum += y[i];
        c++; 
    }
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int k = min(x[a] + y[b], x[b] + y[a]);
        ans[a] -= k;
        ans[b] -= k;
    }
    for(int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    puts("");
}