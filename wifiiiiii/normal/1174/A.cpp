
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[2005];
int main()
{
    int n;
    cin>>n;
    rep(i,2*n) cin>>a[i];
    int ok = 0;
    int idx = 0;
    rep(i,2*n)
    {
        if(a[i]!=a[1]) {idx=i;ok=1;break;}
    }
    if(!ok) {cout<<-1<<endl;return 0;}
    int s1 = 0,s2 = 0;
    rep(i,n) s1+=a[i];
    rep(i,n) s2+=a[i+n];
    if(s1!=s2)
    {
        rep(i,n) cout<<a[i]<<" ";
        rep(i,n)cout<<a[i+n]<<" ";
        cout<<endl;
        return 0;
    }
    else
    {
        if(idx>n)
        {
            swap(a[1],a[idx]);
            int s1 = 0,s2 = 0;
            rep(i,n) s1+=a[i];
            rep(i,n) s2+=a[i+n];
            if(s1!=s2)
            {
                rep(i,n) cout<<a[i]<<" ";
                rep(i,n)cout<<a[i+n]<<" ";
                cout<<endl;return 0;
            }
        }
        else
        {
            swap(a[1],a[2*n]);
            int s1 = 0,s2 = 0;
            rep(i,n) s1+=a[i];
            rep(i,n) s2+=a[i+n];
            if(s1!=s2)
            {
                rep(i,n) cout<<a[i]<<" ";
                rep(i,n)cout<<a[i+n]<<" ";
                cout<<endl;return 0;
            }
            swap(a[2*n],a[idx]);
            s1=0,s2=0;
            rep(i,n) s1+=a[i];
            rep(i,n) s2+=a[i+n];
            if(s1!=s2)
            {
                rep(i,n) cout<<a[i]<<" ";
                rep(i,n)cout<<a[i+n]<<" ";
                cout<<endl;return 0;
            }
        }
    }
}