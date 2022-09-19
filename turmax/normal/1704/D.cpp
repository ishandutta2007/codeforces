#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;vector<int> sums;for(int i=0;i<n;++i) {int sum=0;for(int j=0;j<m;++j) {int x;cin>>x;sum+=(j*x);} sums.push_back(sum);}
        int mi=*min_element(sums.begin(),sums.end());int ma=*max_element(sums.begin(),sums.end());int pos=max_element(sums.begin(),sums.end())-sums.begin();
        cout<<pos+1<<' '<<ma-mi<<'\n';
    }
    return 0;
}