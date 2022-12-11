#include <bits/stdc++.h>
using namespace std;
int v[505];
vector <int> vc;
int main()
{
    long long n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz,a,b,cnt=1;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"! 1";
        return 0;
    }
    for(i=1; i<=n; ++i)
        v[i]=-1;
    for(j=1; j<=n-k+1; ++j)
    {
        cout<<"? ";
        int ck=k;
        for(i=1; ck && i<=n; ++i)
        {
            if(v[i]==-1)
            {
                cout<<i<<' ';
                --ck;
            }
        }
        cout<<'\n';
        cout.flush();
        cin>>a>>b;
        v[a]=b;
    }
    int pz;
    for(i=1; i<=n; ++i)
    {
        if(i!=a && v[i]!=-1)
        {
            pz=i;
            break;
        }
    }
    vc.push_back(a);
    for(i=1; i<=n; ++i)
        if(v[i]==-1)
            vc.push_back(i);
    for(i=1; i<vc.size(); ++i)
    {
        cout<<"? ";
        cout<<pz<<' ';
        for(int y=0; y<vc.size(); ++y)
        {
            if(y!=i)
                cout<<vc[y]<<' ';
        }
        cout<<'\n';
        cout.flush();
        int an,bn;
        cin>>an>>bn;
        if(v[pz]<v[a] && an==a || v[pz]>v[a] && an!=a)
            ++cnt;
    }
    cout<<"! "<<cnt;
    return 0;
}