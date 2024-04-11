#include <bits/stdc++.h>
using namespace std;

int d[105];
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans=1e9;
    for (int i = 1; i <= a; i++)
    {
        cin>>d[i];
        if (i == b) continue;
        if (d[i]&&d[i]<=c) ans = min(ans, abs(i - b));
    }
    cout << ans * 10 << endl;
}