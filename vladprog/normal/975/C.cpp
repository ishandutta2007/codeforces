//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=2e5+100;

int a[N],s[N];

int sum(int l,int r)
{
    return s[r]-s[l-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],s[i]=s[i-1]+a[i];
    int ind=0,hp=0;
    while(q--)
    {
        int k;
        cin>>k;
        if(hp>=k)
            hp-=k;
        else
        {
            k-=hp;
            hp=0;
            int l=ind,r=n;
            while(l<r)
            {
                int m=(l+r+1)/2;
                if(sum(ind+1,m)<=k)
                    l=m;
                else
                    r=m-1;
            }
            k-=sum(ind+1,l);
            ind=l+1;
            hp=a[ind];
            hp-=k;
        }
        if(hp==0)
            ind++,
            hp=a[ind];
        if(ind>n)
            ind=1,
            hp=a[ind];
        cout<<n-ind+1<<"\n";
    }
}