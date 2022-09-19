#include <bits/stdc++.h>

using namespace std;
#define int long long
bool f=false;
void getans(int x)
{
    cout<<"! "<<(x+1)<<endl;
    f=true;
}
int query1(int l1,int r1,int l2,int r2)
{
    cout<<"? "<<r1-l1<<" "<<r2-l2<<endl;
    for(int i=l1;i<r1;++i)
    {
        cout<<i+1<<" ";
    }
    cout<<endl;
    for(int i=l2;i<r2;++i)
    {
        cout<<i+1<<" ";
    }
    cout<<endl;
    string ans;
    cin>>ans;
    if(ans=="FIRST")
    {
        return -1;
    }
    if(ans=="EQUAL")
    {
        return 0;
    }
    if(ans=="SECOND")
    {
        return 1;
    }
    exit(0);
}
int check1(int l,int r)
{
    return query1(0,r-l,l,r);
}
void go(int low,int up)
{
    while(true)
    {
        if((up-low)==1)
        {
            getans(low);
            break;
        }
        int k=(low+up)/2;
        if(check1(low,k)==0)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    bool h=false;
    for(int i=0;i<10;++i)
    {
        int x=rand()%n;
        if(x)
        {
        int ans=query1(0,1,x,x+1);
        if(ans==1)
        {
            getans(0);
            h=true;
            break;
        }
        }
    }
    if(h)
    {
        continue;
    }
    int r=1;
    while(true)
    {
        if((2*r)<=n)
        {
        int ans=check1(r,2*r);
        if(ans==0)
        {
            r*=2;
        }
        else
        {
            int low=r;
            int up=(2*r);
            go(low,up);
            break;
        }
        }
        else
        {
            int low=r;
            int up=n;
            go(low,up);
            break;
        }
    }
    }
    return 0;
}