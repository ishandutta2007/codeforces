#include <bits/stdc++.h>

using namespace std;
#define int long long
mt19937 rnd;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(37824739);
    int n,q;
    cin>>n>>q;
    int a[n];
    vector <int> b[n];
    for(int i=0;i<n;++i) {cin>>a[i];a[i]--;b[a[i]].push_back(i);}
    while(q--) {int l,r;cin>>l>>r;l--;int ans1=0;for(int i=0;i<50;++i) {int x=rnd()%(r-l)+l;int val=a[x];ans1=max(ans1,(int) (lower_bound(b[val].begin(),b[val].end(),r)-lower_bound(b[val].begin(),b[val].end(),l)));} if(ans1<=((r-l+1)/2)) cout<<1<<'\n'; else cout<<(2*ans1-(r-l))<<'\n';}
    return 0;
}