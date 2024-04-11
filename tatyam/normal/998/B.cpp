#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define fcout cout << fixed << setprecision(10)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,budget;
    cin>>n>>budget;
    int a[n];
    int even=0,odd=0;
    vector<int>cost;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n-2){
        if(a[i]&1)odd++;
        else even++;
        if(odd==even)cost.push_back(abs(a[i+1]-a[i]));
    }
    sort(cost.begin(),cost.end());
    int cnt=0;
    for(int i=0;i<cost.size();i++)if(cost[i]<=budget){
        budget-=cost[i];
        cnt++;
    }
    cout<<cnt;
}