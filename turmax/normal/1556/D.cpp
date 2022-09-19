#include <bits/stdc++.h>

using namespace std;
#define int long long
int cnt=(1<<30)-1;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    int u[3][3];int v[3][3];
    cout<<"or 1 2"<<endl;
    cin>>u[0][1];u[1][0]=u[0][1];
    cout<<"or 2 3"<<endl;
    cin>>u[1][2];u[2][1]=u[1][2];
    cout<<"or 1 3"<<endl;
    cin>>u[0][2];u[2][0]=u[0][2];
    cout<<"and 1 2"<<endl;
    cin>>v[0][1];v[1][0]=v[0][1];
    cout<<"and 2 3"<<endl;
    cin>>v[1][2];v[2][1]=v[1][2];
    cout<<"and 1 3"<<endl;
    cin>>v[0][2];v[2][0]=v[0][2];
    for(int i=0;i<3;++i)
    {
        a[i]=(u[i][(i+1)%3] & u[i][(i+2)%3])-(v[(i+1)%3][(i+2)%3] & (cnt-v[i][(i+1)%3]) & (cnt-v[i][(i+2)%3]));
    }
    for(int i=3;i<n;++i)
    {
        cout<<"and 1 "<<i+1<<endl;
        int ans1;cin>>ans1;
        cout<<"or 1 "<<i+1<<endl;
        int ans2;cin>>ans2;
        a[i]=(ans1+ans2-a[0]);
    }
    sort(a,a+n);
    cout<<"finish "<<a[k-1]<<endl;
    return 0;
}