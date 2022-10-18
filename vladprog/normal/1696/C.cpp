#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=5e4+100;

int a[N],b[N];

bool solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
        cin>>b[i];
    int i=0,j=0;
    int vala=0,cnta=0,valb=0,cntb=0;
    while(true)
    {
        if(cnta==0)
        {
            i++;
            if(i<=n)
            {
                vala=a[i];
                cnta=1;
                while(vala%m==0)
                    vala/=m,
                    cnta*=m;
            }
        }
        if(cntb==0)
        {
            j++;
            if(j<=k)
            {
                valb=b[j];
                cntb=1;
                while(valb%m==0)
                    valb/=m,
                    cntb*=m;
            }
        }
//        cout<<i<<" "<<vala<<" "<<cnta<<" | "<<j<<" "<<valb<<" "<<cntb<<endl;
        if(i==n+1&&j==k+1)
            return true;
        if(i==n+1||j==k+1)
            return false;
        if(vala!=valb)
            return false;
        int cur=min(cnta,cntb);
        cnta-=cur;
        cntb-=cur;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"Yes\n":"No\n");
}