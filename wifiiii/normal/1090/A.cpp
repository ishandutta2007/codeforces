#include<iostream>
using namespace std;

int a[200005],b[200005];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int maxxx = -1;
    long long ans = 0;
    for(int i=1;i<=n;++i)
    {
        int m;
        cin>>m;
        int maxx = -1;
        for(int j=1;j<=m;++j)
        {
            int M;
            cin>>M;
            maxx = max(maxx, M);
        }
        a[i] = maxx, b[i] = m;
        maxxx = max(maxx, maxxx);
    }
    for(int i=1;i<=n;++i)
    {
        if(maxxx - a[i] == 0) continue;
        ans += 1LL * b[i] * (maxxx - a[i]);
    }
    cout << ans << endl;
}