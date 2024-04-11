#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

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
        for(int k=2;k<=30;k++)
        {
            int p=(1ll<<k)-1;
            if(n%p==0)
            {
                cout<<n/p<<"\n";
                break;
            }
        }
    }
}