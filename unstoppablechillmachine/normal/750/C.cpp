#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second

vector<pair<ll,ll> > Vec;
ll l,r,mid,now,n,max1=-1e18;;
bool t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    Vec.resize(n);
    for (int i=0;i<n;i++)
    {
        cin>>Vec[i].f>>Vec[i].sec;
    }

    l=-1e18;
    r=1e18;
    while (r-l>1)
    {
        t=false;
        mid=(r+l)/2;
        now=mid;
        for (int i=0;i<n;i++)
        {
            if (Vec[i].sec==1 && now<1900)
            {
                t=true;
                l=mid;
                break;
            }
            else if (Vec[i].sec==2 && now>=1900)
            {
                t=true;
                r=mid;
                break;
            }
            now+=Vec[i].f;
        }
        if (!t)
        {
            l=mid;
            max1=max(now,max1);
        }
        //cout<<l<<endl;
    }

    if (max1>1e17) cout<<"Infinity";
    else if (max1<-1e17) cout<<"Impossible";
    else cout<<max1;

    return 0;
}