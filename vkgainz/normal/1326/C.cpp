#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    int p[n];
    for(int i=0;i<n;i++)
        cin >> p[i];
    vector<int> nums;
    for(int i=0;i<n;i++)
        if(p[i]>=n-k+1)
            ans+=p[i];
    for(int i=0;i<n;i++)
        if(p[i]>=n-k+1)
            nums.push_back(i);
    ll prod = 1;
    for(int i=0;i<nums.size()-1;i++){
        prod*=(ll) (nums[i+1]-nums[i]);
        prod%=998244353;
    }
    if(prod<0) prod+=998244353;
    cout << ans << " " << prod << endl;
}