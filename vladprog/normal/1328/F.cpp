#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],pref[N];

int sum(int l,int r)
{
    return pref[r]-pref[l-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i+k-1<=n;i++)
        if(a[i]==a[i+k-1])
            cout<<0,exit(0);
    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1]+a[i];
    int ans=1e18;
    for(int pos=1;pos<=k;pos++)
    {
        int val=a[pos];
        int res1=val*(pos-1)-sum(1,pos-1);
        int res2=sum(pos+1,k)-val*(k-pos);
        int res3=(a[k]==val?0ll:sum(k+1,n)-(val+1)*(n-k));
        ans=min(ans,res1+res2+res3);
    }
    for(int l=1,r=k;r<=n;l++,r++)
    {
        int val=a[r];
        int res1=(val-1)*(l-1)-sum(1,l-1);
        int res2=val*k-sum(l,r);
        ans=min(ans,res1+res2);
    }
    for(int i=1;i<=n;i++)
        a[i]=-a[i];
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1]+a[i];
    for(int pos=1;pos<=k;pos++)
    {
        int val=a[pos];
        int res1=val*(pos-1)-sum(1,pos-1);
        int res2=sum(pos+1,k)-val*(k-pos);
        int res3=(a[k]==val?0ll:sum(k+1,n)-(val+1)*(n-k));
        ans=min(ans,res1+res2+res3);
    }
    for(int l=1,r=k,pos=k;r<=n;l++,r++,pos++)
    {
        int val=a[r];
        int res1=(val-1)*(l-1)-sum(1,l-1);
        int res2=val*k-sum(l,r);
        ans=min(ans,res1+res2);
    }
    cout<<ans;
}