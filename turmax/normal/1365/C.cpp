#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> u[n];
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];a[i]--;}
    int b[n];
    for(int i=0;i<n;++i) {cin>>b[i];b[i]--;}
    for(int i=0;i<n;++i)
    {
        u[a[i]].first=i;
        u[b[i]].second=i;
    }
    int o[n];
    for(int i=0;i<n;++i) o[i]=0;
    for(int i=0;i<n;++i)
    {
        //cout<<(u[i].first-u[i].second+n)%n<<endl;
        o[(u[i].first-u[i].second+n)%n]++;
    }
    cout<<*max_element(o,o+n);
    return 0;
}