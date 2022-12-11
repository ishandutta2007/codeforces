#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> t[N];
int l[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        t[p].push_back(i);
    }
    for(int i = n; i >= 1; i--)
    {
        if(t[i].empty()) l[i] = 1;
        for(int j: t[i])
            l[i] += l[j];
    }
    sort(l + 1, l + n + 1);
    for(int i = 1; i <= n; i++)
        printf("%d ", l[i]);
    puts("");
}