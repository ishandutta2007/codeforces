#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int x,int val)
{
    if(val<=0) return x;
    int low=0;int up=x;
    while(up-low>1)
    {
        int cnt=(low+up)/2;int x1=(x/cnt);int o2=(x-cnt*x1);int o1=(cnt-o2);
        int val2=(o1*x1*x1+o2*(x1+1)*(x1+1));
        int cnt1=cnt+1; x1=(x/cnt1); o2=(x-cnt1*x1); o1=(cnt1-o2);
        int val3=(o1*x1*x1+o2*(x1+1)*(x1+1));
        if(val2-val3>val) {low=cnt;}
        else {up=cnt;}
    }
    int cnt=up;int x1=(x/cnt);int o2=(x-cnt*x1);int o1=(cnt-o2);int val2=(o1*x1*x1+o2*(x1+1)*(x1+1));return val2;
}
int f2(int x,int val)
{
    if(val<=0) return x-1;
    int low=0;int up=x;
    while(up-low>1)
    {
        int cnt=(low+up)/2;int x1=(x/cnt);int o2=(x-cnt*x1);int o1=(cnt-o2);
        int val2=(o1*x1*x1+o2*(x1+1)*(x1+1));
        int cnt1=cnt+1; x1=(x/cnt1); o2=(x-cnt1*x1); o1=(cnt1-o2);
        int val3=(o1*x1*x1+o2*(x1+1)*(x1+1));
        if(val2-val3>val) {low=cnt;}
        else {up=cnt;}
    }
    int cnt=up;int x1=(x/cnt);int o2=(x-cnt*x1);int o1=(cnt-o2);int val2=(o1*x1*x1+o2*(x1+1)*(x1+1));return cnt-1;
}
int f3(int x,int val)
{
    if(f(x,val)==f(x,val+1)) return 0;
    return (f(x,val)-f(x,val+1))/(-f2(x,val)+f2(x,val+1));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;vector<int> v;int a[n];for(int i=0;i<n;++i) cin>>a[i]; v.push_back(a[0]);for(int i=1;i<n;++i) v.push_back(a[i]-a[i-1]); int val;cin>>val;int cur=0;for(auto h:v) cur+=(h*h);if(cur<=val) {cout<<0;return 0;}
    int low=(-1);int up=1e18;
    while(up-low>1)
    {
        int x=(low+up)/2;int ans=0;
        for(auto h:v)
        {
            ans+=f(h,x);
        }
        if(ans>val) up=x;
        else low=x;
    }
    int x=up;int ans=0;int cnt=0;
    for(auto h:v)
        {
            cnt+=f2(h,x);ans+=f(h,x);
        }
        //cout<<ans<<" ans "<<cnt<<" cnt "<<x<<" x "<<endl;
        if(ans==val) {cout<<cnt;return 0;}
    cout<<(ans-val+x-1)/x+cnt;
    return 0;
}
/*
1
100
239
*/