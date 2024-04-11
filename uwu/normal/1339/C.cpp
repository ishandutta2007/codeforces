#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> powers;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    powers.push_back(0); powers.push_back(1);
    for (int i=2;i<=33;++i){
        powers.push_back(powers[i-1]*2);
    }
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr={0};
        for (int i=1,a;i<=n;++i){
            cin >> a; arr.push_back(a);
        }
        arr[0]=arr[1];
        int ans=0;
        for (int i=1;i<=n;++i){
            if (arr[i]>=arr[i-1]) continue;
            ans=max(ans,upper_bound(powers.begin(),powers.end(),arr[i-1]-arr[i])-powers.begin()-1);
            arr[i]=arr[i-1];
        }
        cout << ans << '\n';
    }
}