#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = n - 1; i > 0; i--)
        a[i] -= a[i-1];
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        bool ok = true;
        for(int j = 0; j + i < n; j++)
            if(a[j] != a[j+i]) ok = false;
        if(ok) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for(int x: ans)
        printf("%d ", x);
    puts("");
}