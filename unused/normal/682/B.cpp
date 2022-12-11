#include <bits/stdc++.h>
using namespace std;

int dat[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&dat[i]);
    sort(dat+1,dat+n+1);
    for (int i = 1; i <= n; i++)
    {
        dat[i] = min(dat[i], dat[i-1] + 1);
    }
    printf("%d\n", dat[n] + 1);
}