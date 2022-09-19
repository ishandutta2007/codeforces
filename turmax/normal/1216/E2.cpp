#include <bits/stdc++.h>

using namespace std;
#define int long long
string sti(int x)
{
    string ans;
    if(x==0)
    {
        return "0";
    }
    while(x!=0)
    {
        ans.push_back(x%10+'0');
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int po[10];
int go2(int x)
{
    if(x<10)
    {
        return x;
    }
    int z=upper_bound(po,po+10,x)-po;
    z--;
    int r=po[z];
    int ans=(x-r+1)*(z+1);
    ans+=go2(r-1);
    return ans;
}
int go3(int x)
{
    if(!x)
    {
        return 0;
    }
    if(x==1)
    {
        return 1;
    }
    int z=upper_bound(po,po+10,x)-po;
    z--;
    int r=po[z];
    int h=(x-r+1);
    int ans=(h*(h+1))/2*(z+1);
    ans+=(go3(r-1)+go2(r-1)*h);
    return ans;
}
char go1(int x)
{
    //cout<<x<<" x "<<endl;
    if(x<=9)
    {
        return '0'+x;
    }
    int low=0;
    int up=1e9;
    while(true)
    {
        if((up-low)==1)
        {
            int z=go2(low);
            int r=(x-z);
            return sti(low+1)[r-1];
        }
        int k=(low+up)/2;
        int res=go2(k);
        if(res<x)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
}
char go(int x)
{
    int low=0;
    int up=(1e9/2);
    int k;
    while(true)
    {
        //cout<<low<<" "<<up<<endl;
        if((up-low)==1)
        {
            int r=low;
            int u=x-go3(r);
            //cout<<r<<" "<<u<<" ru "<<endl;
            return go1(u);
        }
        k=(low+up)/2;
        int res=go3(k);
        if(res<x)
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
    int u=1;
    for(int i=0;i<10;++i)
    {
        po[i]=u;
        u*=10;
    }
    int q;
    cin>>q;
    while(q--)
    {
    int x;
    cin>>x;
    cout<<go(x)<<endl;
    }
    return 0;
}