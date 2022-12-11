#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    long long n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long xorc=0;
        sc=0;
        for(i=1;i<=n;++i)
        {
            xorc^=v[i];
            sc+=v[i];
        }
        if(xorc*2LL==sc)
        {
            cout<<"0\n\n";
            continue;
        }
      /*  if(xorc*2LL>sc && sc%2LL==0)
        {
            if(sc%2LL==0)
                cout<<2<<'\n'<<(xorc*2LL-sc)/2LL<<' '<<(xorc*2LL-sc)/2LL<<'\n';
            else
                {
                    cout<<3<<'\n'<<1<<' ';
                    ++sc;
                    xorc^=1LL;
                    cout<<(xorc*2LL-sc)/2LL<<' '<<(xorc*2LL-sc)/2LL<<'\n';
                }
            continue;
        }*/

        cout<<3<<'\n';
        long long inv=(long long)xorc^((1LL<<58LL)-1LL);
        if((sc+inv)%2LL==1LL)
            inv^=1LL;
        sc+=inv;
        xorc^=inv;
        cout<<inv<<' ';
        cout<<(xorc*2LL-sc)/2LL<<' '<<(xorc*2LL-sc)/2LL<<'\n';
    }
    return 0;
}