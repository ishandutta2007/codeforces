#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> res1;
vector <int> res2;
void slv(int n,int m,int low,int up)
{
    if(n==0)
    {
        return;
    }
    if(n==1)
    {
        res1.push_back(low);
        res2.push_back(up);
        return;
    }
    if(m>=(n-1))
    {
        res1.push_back(low);
        res1.push_back(up);
        res2.push_back(up);
        res2.push_back(low);
        slv(n-2,m-(n-1),low+1,up-1);
    }
    else
    {
        res1.push_back(low);
        res2.push_back(low);
        slv(n-1,m,low+1,up);
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int d;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        sum+=max(i,n+1-i);
    }
    if(m>sum)
    {
        m=sum;
    }
    d=m;
    for(int i=1;i<=n;++i)
    {
        m-=i;
    }
    if(m<0)
    {
        cout<<(-1);
        return 0;
    }
    slv(n,m,1,n);
    int s=0;
    cout<<d<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<res1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<res2[i]<<" ";
    }
    return 0;
}