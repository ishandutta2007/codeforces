#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int g[N];
vector<int> v[10];

int f(int x)
{
    int ans = 1;
    while(x > 0)
    {
        int a = x % 10;
        if(a) ans *= a;
        x /= 10;
    }
    return ans;
}

int main()
{
    for(int i = 1; i < N; i++)
    {
        g[i] = i < 10 ? i : g[f(i)];
        v[g[i]].push_back(i);
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", upper_bound(v[k].begin(), v[k].end(), r) - lower_bound(v[k].begin(), v[k].end(), l));
    }
}