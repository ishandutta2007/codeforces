#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15)<<"";
    int n,r;
    cin>>n>>r;
    int a[1<<n];
    int sum=0;
    for(int i=0;i<(1<<n);++i) {cin>>a[i];sum+=a[i];}
    for(int i=0;i<=r;++i)
    {
        cout<<(sum+0.0)/((1<<n)+0.0)<<endl;
        int l,x;
        if(i!=r){
        cin>>l>>x;
        sum-=a[l];
        sum+=x;
        a[l]=x;
        }
    }
    return 0;
}