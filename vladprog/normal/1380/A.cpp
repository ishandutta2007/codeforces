#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int p[N],pref[N],suff[N];

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
            cin>>p[i];
        pref[1]=1;
        for(int i=2;i<=n;i++)
            if(p[i]<p[pref[i-1]])
                pref[i]=i;
            else
                pref[i]=pref[i-1];
        suff[n]=n;
        for(int i=n-1;i>=1;i--)
            if(p[i]<p[suff[i+1]])
                suff[i]=i;
            else
                suff[i]=suff[i+1];
        bool yes=false;
        for(int i=2;i<=n-1;i++)
            if(p[i]>p[pref[i-1]]&&
               p[i]>p[suff[i+1]])
            {
                cout<<"YES\n"<<pref[i-1]<<" "<<i<<" "<<suff[i+1]<<"\n";
                yes=true;
                break;
            }
        if(!yes)
            cout<<"NO\n";
    }
}