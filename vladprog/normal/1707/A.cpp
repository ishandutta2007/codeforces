#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int lo=1,hi=n;
        while(lo<hi)
        {
            int mi=(lo+hi)/2;
            int cur=q;
            for(int i=mi;i<=n;i++)
                if(a[i]>cur)
                    cur--;
//            cout<<mi<<" -> "<<cur<<endl;
            if(cur>=0)
                hi=mi;
            else
                lo=mi+1;
        }
//        cout<<lo<<endl;
        for(int i=1;i<lo;i++)
            cout<<(a[i]<=q);
        for(int i=lo;i<=n;i++)
            cout<<1;
        cout<<"\n";
    }
}