#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second

const ld eps=0.00000001;

vector<pair<ld,ld> > Vec;
ld l,r,mid,min1,max1;
ll n;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    Vec.resize(n);
    for (int i=0;i<n;i++)
    {
        cin>>Vec[i].f;
    }
    for (int i=0;i<n;i++)
    {
        cin>>Vec[i].sec;
    }

    l=0;
    r=1e18+1;

    while (r-l>eps)
    {
        mid=(l+r)/2;
        min1=-1e18;
        max1=1e18;
        for (int i=0;i<n;i++)
        {
            min1=max(min1,Vec[i].f-Vec[i].sec*mid);
            max1=min(max1,Vec[i].f+Vec[i].sec*mid);
        }
        if (max1-min1>=-eps) r=mid;
        else l=mid;
    }

    cout<<setprecision(7)<<l;



    return 0;
}