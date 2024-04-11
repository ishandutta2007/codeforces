#include <bits/stdc++.h>

using namespace std;

int cnt[10010];

int C(int n)
{
    return (n*(n-1))/2;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        //ke[u].push_back(v);
        //ke[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    long long res = 0;
    for(int i=1; i<=n; i++)
    {
        res += C(cnt[i]);
    }
    cout<<res<<endl;
    return 0;
}