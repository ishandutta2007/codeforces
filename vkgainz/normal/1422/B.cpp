#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll make(ll a,ll b, ll c, ll d){
    vector<ll> x;
    x.push_back(a), x.push_back(b), x.push_back(c), x.push_back(d);
    sort(x.begin(),x.end());
    ll ret = a+b+c+d-4*x[0];
    ret = min(ret,abs(a-x[0])+abs(b-x[0])+abs(c-x[0])+abs(d-x[0]));
    ret = min(ret,abs(a-x[1])+abs(b-x[1])+abs(c-x[1])+abs(d-x[1]));
    ret = min(ret,abs(a-x[2])+abs(b-x[2])+abs(c-x[2])+abs(d-x[2]));
    ret = min(ret,abs(a-x[3])+abs(b-x[3])+abs(c-x[3])+abs(d-x[3]));
    return ret;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ll grid[n][m];
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++)
                cin >> grid[i][j];
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=make(grid[i][j],grid[n-i-1][j],grid[i][m-1-j],grid[n-i-1][m-1-j]);
            }
        }
        ans/=4;
        cout << ans << endl;

    }
}