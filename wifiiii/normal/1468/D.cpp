#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> c(m);
        for(int i=0;i<m;++i) cin>>c[i];
        sort(c.begin(), c.end());
        int mt = 0;
        if(a < b) mt = b - 1;
        else mt = n - b;
        int mm = min(m, abs(a-b)-1);
        int ans = 0;
        int lo = 0, hi = mm;
        while(lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            int ok = 1;
            for(int j = 0, i = mid - 1; i >= 0; --i, ++j)
            {
                 if(1 + j + c[i] > mt)
                 {
                     ok = 0;
                     break;
                 }
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << endl;
    }
}