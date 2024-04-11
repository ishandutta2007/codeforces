#include <bits/stdc++.h>
using namespace std;
int n, a[100001], cnt[40];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; ++ i)
    {
        cin>>a[i];
        for (int j = 0; j <= 30; ++ j)
        if (a[i] & (1<<j)) cnt[j] ++;
    } 
    int flg = 0;
    for (int j = 30; j >= 0 && !flg; -- j)
    {
        if (cnt[j] != 1) continue;
        for (int i = 1; i <= n; ++ i)
        if (a[i] & (1 << j))
        {swap(a[i], a[1]); flg = 1; break;}
    }
    for (int i = 1; i <= n; ++ i)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}