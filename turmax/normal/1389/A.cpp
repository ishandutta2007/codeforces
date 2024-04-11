#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    int l,r;
    cin>>l>>r;
    if(r>=2*l) cout<<l<<" "<<2*l<<endl;
    else cout<<(-1)<<" "<<(-1)<<endl;
    }
    return 0;
}