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
        if(k==n-1)
        {
            if(n<8)
            {
                cout<<-1<<"\n";
                continue;
            }
            cout<<n-1<<" "<<n/2-1<<"\n";
            cout<<n/2<<" "<<n/2+1<<"\n";
            cout<<0<<" "<<n/2-2<<"\n";
            for(int i=1;i<n/2-2;i++)
            {
                int a=i;
                int b=i^(n-1);
                if(a==k)
                    a=0;
                if(b==k)
                    b=0;
                cout<<a<<" "<<b<<"\n";
            }
        }
        else
        {
            cout<<k<<" "<<n-1<<"\n";
            for(int i=1;i<n/2;i++)
            {
                int a=i;
                int b=i^(n-1);
                if(a==k)
                    a=0;
                if(b==k)
                    b=0;
                cout<<a<<" "<<b<<"\n";
            }
        }
    }
}