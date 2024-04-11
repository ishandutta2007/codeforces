#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int last=0,cnt=0;
        while(n--)
        {
            int a;
            cin>>a;
            if(!last&&a)
                cnt++;
            last=a;
        }
        cout<<min<int>(2,cnt)<<"\n";
    }
}