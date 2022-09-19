#include <bits/stdc++.h>

using namespace std;
#define int long long
bool check(int n,int m,int low,int mid)
{
    int o=(mid-1-low);
    int z1=((low^n)/(o+1))*(o+1);
    int z2=z1+o;
    return (z2<=m);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int low=0;int up=(1LL<<31);
        while(true)
        {
            if((up-low)==1)
            {
                cout<<low<<'\n';
                break;
            }
            int mid=(low+up)/2;
            if(check(n,m,low,mid)) low=mid;
            else up=mid;
        }
    }
    return 0;
}