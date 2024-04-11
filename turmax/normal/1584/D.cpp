#include <bits/stdc++.h>

using namespace std;
#define int long long
int query(int l,int r)
{
    cout<<"? "<<(l+1)<<' '<<r<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int go(int x)
{
    if(x<0) return (-1e9);
    int low=0;
    int up=1e9;
    while((up-low)>1)
    {
        int mid=(low+up)/2;
        if(mid*(mid-1)>x) up=mid;
        else low=mid;
    }
    return low;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int low=0;int up=n;
        int ans0=query(0,n);
        while((up-low)>1)
        {
            int mid=(low+up)/2;
            int ans=query(0,mid);
            if(ans==0)
            {
                 low=mid;
            }
            else
            {
                up=mid;
            }
        }
        int pos=low-1;
        int o=sqrt(2*ans0);
        if(o*o!=(2*ans0)) ++o;
        int ans=query(pos,pos+o);ans*=2;ans+=o;ans*=2;ans-=(o*o);int z=sqrt(ans);
        int f=(ans0*2);
        int a1=(o+z)/2;int a2=(o-z)/2;int b1=go(f-a1*(a1-1));int b2=go(f-a2*(a2-1));
        int ansa;
        int ansb;
        if(a1*(a1-1)+b1*(b1-1)!=f)
        {
            ansa=a2;
            ansb=b2;
        }
        else if(a2*(a2-1)+b2*(b2-1)!=f)
        {
            ansa=a1;
            ansb=b1;
        }
        else
        {
            if(a1>a2) {swap(a1,a2);swap(b1,b2);}
            int o2=query(pos,pos+a2);
            if(o2==(a2*(a2-1))/2)
            {
                ansa=a2;
                ansb=b2;
            }
            else
            {
                ansa=a1;
                ansb=b1;
            }
        }
        cout<<"! "<<pos+1<<' '<<pos+ansa+1<<' '<<pos+ansa+ansb<<endl;
    }
    return 0;
}