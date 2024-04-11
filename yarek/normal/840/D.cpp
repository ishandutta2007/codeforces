#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
vector<int> occ[N];
int a[N];
bool checked[N];

bool check(int l, int r, int k, int x)
{
    return occ[x].size() * k > (r - l + 1) &&
        (upper_bound(occ[x].begin(), occ[x].end(), r) - lower_bound(occ[x].begin(), occ[x].end(), l)) * k > (r - l + 1);
}

unsigned rrand()
{
    return (unsigned)rand() * 10000u + (unsigned)rand();
}

int main()
{
    unsigned int k = 431;
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        k = k * 1009 + a[i] ^ a[i];
        occ[a[i]].push_back(i);
    }
    srand(k);
    vector<int> vec;
    while(q--)
    {
        int l, r, k, ans = N;
        scanf("%d %d %d", &l, &r, &k);
        int found = 0;
        for(int i = 0; i < 80 && found < k; i++)
        {
            int t = a[rrand() % (r - l + 1) + l];
            if(checked[t]) continue;
            checked[t] = true;
            vec.push_back(t);
            if(check(l, r, k, t))
            {
                found++;
                ans = min(ans, t);
            }
        }
        for(auto x: vec)
            checked[x] = false;
        vec.clear();
        printf("%d\n", ans == N ? -1 : ans);
    }
}