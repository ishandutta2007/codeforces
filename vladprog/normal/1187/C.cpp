#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1010;

int a[N],l[N],r[N],t[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int j=2;j<=n;j++)
        a[j]=-1;
    for(int i=1;i<=m;i++)
    {
        cin>>t[i]>>l[i]>>r[i];
        l[i]++;
        if(t[i])
            for(int j=l[i];j<=r[i];j++)
                a[j]=1;
    }
//    for(int j=1;j<=n;j++)
//        cout<<a[j]<<" ";
//    cout<<"\n";
    for(int i=1;i<=m;i++)
        if(!t[i])
        {
            bool ok=false;
//            cout<<l[i]<<" "<<r[i]<<"\n";
            for(int j=l[i];j<=r[i];j++)
                if(a[j]==-1)
                    ok=true;
            if(!ok)
                cout<<"NO",exit(0);
        }
    a[1]=N;
    for(int j=2;j<=n;j++)
        a[j]+=a[j-1];
    cout<<"YES\n";
    for(int j=1;j<=n;j++)
        cout<<a[j]<<" ";
}