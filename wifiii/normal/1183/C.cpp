#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)
#define int ll
int32_t main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int k,n,a,b;
        cin>>k>>n>>a>>b;
        if(k<=n*b)
        {
            cout<<-1<<endl;
            continue;
        }
        int lo=0,hi=n;
        while(lo<hi)
        {
            int m=(lo+hi+1)/2;
            if(k <= m*a+(n-m)*b) hi=m-1;
            else lo=m;
        }
        cout<<lo<<endl;
    }
}