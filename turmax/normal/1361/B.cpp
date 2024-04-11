#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int po1(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po1(a,b/2);
        return min((int) 1e9,u*u);
    }
    int u=po1(a,b-1);
    return min(a*u,(int) 1e9);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    //cout<<po(5,100)<<endl;
    while(t--)
    {
    int n,p1;
    cin>>n>>p1;
    vector <int> a(n);
    int b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(p1==1)
    {
        cout<<(n%2)<<endl;
        continue;
    }
    sort(a.begin(),a.begin()+n);
    for(int i=0;i<n;++i)
    {
        b[i]=po(p1,a[i]);
    }
    int ans=0;
    int ans1=0;
    for(int i=n-1;i>=0;i--)
    {
        if(i!=(n-1))
        {
        int x=po1(p1,a[i+1]-a[i]);
        ans=min((int) 1e9,ans*x);
        }
        if(ans!=0)
        {
            ans1-=b[i];
            ans--;
        }
        else
        {
            ans1+=b[i];
            ans++;
        }
        ans1%=p;
    }
    ans1+=p;
    ans1%=p;
    cout<<ans1<<endl;
    }
    return 0;
}