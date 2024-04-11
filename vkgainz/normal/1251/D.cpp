#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t;
int n;
ll s;
vector<pair<ll,ll>> employee;
bool works(ll curr){
    set<pair<ll, ll>> mid;
    ll totCost =0;
    ll numLeft =0;
    ll numRight=0;
    for(int i=0;i<n;i++){
        if(employee[i].second<curr){
            numLeft++;
            totCost+=employee[i].first;
        }
        else if(employee[i].first>=curr){
            numRight++;
            totCost+=employee[i].first;
        }
        else{
            mid.insert({employee[i].first,i});
        }
    }
    if(numLeft>(n-1)/2){
        return false;
    }
    int numTake = (n-1)/2-numLeft;
    auto it = mid.begin();
    while(it!=mid.end()){
        if(numTake>0){
            totCost+=it->first;
            numTake--;
        }
        else{
            totCost+=curr;
        }
        it++;
    }
    return totCost<=s;
}
ll binarySearch(ll lo,ll hi){
    ll mid = (lo+hi)/2;
    if(works(mid)){
        if(!works(mid+1)){
            return mid;
        }
        return binarySearch(mid+1,hi);
    }
    else{
        if(works(mid-1)){
            return mid-1;
        }
        return binarySearch(lo,mid-1);
    }
}
void solve(){
    ll ans = binarySearch(0,s);
    cout << ans << endl;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        employee.clear();
        for(int i=0;i<n;i++){
            ll l,r;
            cin >> l >> r;
            employee.push_back({l,r});
        }
        solve();

    }
}