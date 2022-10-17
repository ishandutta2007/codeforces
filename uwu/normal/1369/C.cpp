#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        vector<int> arr(n), w(k);
        for (int i=0;i<n;++i) cin >> arr[i];
        for (int i=0;i<k;++i) cin >> w[i];
        sort(arr.begin(),arr.end(),greater<int>());
        sort(w.begin(),w.end());
        ll tot=0;
        for (int i=0;i<k;++i) tot+=arr[i];
        int p=k;
        for (int i=0;i<k;++i){
            if (w[i]==1){ tot+=arr[i]; continue; }
            p+=w[i]-1;
            tot+=arr[p-1];
            
        } 
        cout << tot << '\n';
    }
}