#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    int m;
    cin >> n >> m >> k;
    set<ll> curr;
    for(int i=0;i<m;i++){
        ll p; cin>> p;
        curr.insert(p);
    }
    auto it = curr.begin();
    ll r = k;
    int numSteps = 0;
    while(it!=curr.end()){
        if((*it)<=r){
            int temp = 0;
            while(it!=curr.end() && (*it)<=r){
                ++temp;
                curr.erase(it++);
            }
            ++numSteps;
            r+=temp;
        }
        else{
            ll x = ((*it)-r+k-1)/k;
            r = r+x*k;
        }
    }
    cout << numSteps << endl;
}