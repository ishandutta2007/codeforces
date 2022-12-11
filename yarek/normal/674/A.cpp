#include <bits/stdc++.h>
using namespace std;

int t[5000];
int ans[5001];
int k[5001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", t + i);
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n; j++)
            k[j] = 0;
        pair<int, int> dom(0, 0);
        for(int j = i; j < n; j++)
        {
            k[t[j]]++;
            dom = max(dom, make_pair(k[t[j]], -t[j]));
            ans[-dom.second]++;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");
}