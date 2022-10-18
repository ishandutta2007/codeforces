#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;
int a[N];

bool prime(int x)
{
    if(x==1)
        return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}

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
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int sum=accumulate(a+1,a+n+1,0ll);
        if(!prime(sum))
        {
            cout<<n<<"\n";
            for(int i=1;i<=n;i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            int odd=-1;
            for(int i=1;i<=n;i++)
                if(a[i]%2)
                {
                    odd=i;
                    break;
                }
            cout<<n-1<<"\n";
            for(int i=1;i<=n;i++)
                if(i!=odd)
                    cout<<i<<" ";
            cout<<"\n";
        }
    }
}