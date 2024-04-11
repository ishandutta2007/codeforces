#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int D=50;

int a[D];

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
        n--;
        int l=1,r=40;
        while(l<r)
        {
            int d=(l+r)/2;
            int cnt=1,sum=d;
            for(int i=1;i<=d;i++)
            {
                a[i]=min(cnt,(n-sum)/(d-i+1));
                cnt+=a[i];
                sum+=a[i]*(d-i+1);
            }
            if(sum==n)
                r=d;
            else
                l=d+1;
        }
        int d=(l+r)/2;
        int cnt=1,sum=d;
        for(int i=1;i<=d;i++)
        {
            a[i]=min(cnt,(n-sum)/(d-i+1));
            cnt+=a[i];
            sum+=a[i]*(d-i+1);
        }
        if(sum==n)
            r=d;
        else
            l=d+1;
        cout<<d<<"\n";
        for(int i=1;i<=d;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}