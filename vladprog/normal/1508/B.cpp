#include <bits/stdc++.h>

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
        int n,k;
        cin>>n>>k;
        if(n<62&&k>(1ll<<(n-1)))
        {
            cout<<-1<<"\n";
            continue;
        }
        k--;
        k*=2;
        int nxt=1,len=1;
        for(int i=n-1;i>=0;i--)
        {
            int bit=(i<62?((k>>i)&1):0);
            if(bit)
                len++;
            else
            {
                for(int val=nxt+len-1;val>=nxt;val--)
                    cout<<val<<" ";
                nxt+=len;
                len=1;
            }
        }
        cout<<"\n";
    }
}