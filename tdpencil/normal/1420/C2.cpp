#include<iostream>

using namespace std;

#define int long long

int a[1000000+5];

int n;

int ans=0;

inline void insert(int i)
{
    if (i==0||i==n+1) return;
    if (a[i-1]<a[i]&&a[i]>a[i+1]) ans+=a[i];
    if (a[i-1]>a[i]&&a[i]<a[i+1]) ans-=a[i];
}

inline void erase(int i)
{
    if (i==0||i==n+1) return;
    if (a[i-1]<a[i]&&a[i]>a[i+1]) ans-=a[i];
    if (a[i-1]>a[i]&&a[i]<a[i+1]) ans+=a[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int q;
        cin>>n>>q;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        a[0]=-1;
        a[n+1]=-1;
        ans=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i-1]<a[i]&&a[i]>a[i+1]) ans+=a[i];
            if (a[i-1]>a[i]&&a[i]<a[i+1]) ans-=a[i];
        }
        cout<<ans<<'\n';
        while (q--)
        {
            int l,r;
            cin>>l>>r;
            erase(l-1);
            erase(l);
            erase(l+1);
            if (l!=r)
            {
                if (r-1!=l+1&&r-1!=l) erase(r-1);
                if (r!=l+1) erase(r);
                erase(r+1);
            }
            swap(a[l],a[r]);
            insert(l-1);
            insert(l);
            insert(l+1);
            if (l!=r)
            {
                if (r-1!=l+1&&r-1!=l) insert(r-1);
                if (r!=l+1) insert(r);
                insert(r+1);
            }
            cout<<ans<<'\n';
        }
    }
}