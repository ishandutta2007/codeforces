#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int d=abs(a-b);
        int s=0;
        for(int n=0;;n++)
        {
            s+=n;
            if(s>=d&&s%2==d%2)
            {
                cout<<n<<"\n";
                break;
            }
        }
    }
}