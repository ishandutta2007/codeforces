#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        for(int i=1;i<=n;++i) a[i] = 1;
        for(int i=1;i<=m;++i)
        {
            int x;
            cin >> x;
            a[x] = 0;
        }
        if((n - m) % (k - 1))
        {
            cout << "NO" << endl;
            continue;
        }
        int ok = 0;
        int l = 0, r = n - m;
        for(int i=1;i<=n;++i)
        {
            if(a[i]) --r;
            if(a[i] == 0 && r >= (k-1)/2 && l >= (k-1)/2) ok = 1;
            if(a[i]) ++l;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}