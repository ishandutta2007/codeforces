#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        vector<int> arr;
        int n; cin >> n;
        for (int i=0,a;i<n;++i){
            cin >> a; arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        int index=((n+1)/2)-1;
        int l=index-1,r=index+1;
        cout << arr[index] << " ";
        while (l>=0||r<=n-1){
            if (r<=n-1) cout << arr[r] << " ";
            if (l>=0) cout << arr[l] << " ";
            l--; r++;
        }
        cout << '\n';
    }
}