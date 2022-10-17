#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        priority_queue<int> pq;
        vector<int> b;
        for (int i=0,x;i<n;++i){
            cin >> x;
            pq.push(x);
        }
        for (int i=0,x;i<n;++i){
            cin >> x;
            b.push_back(x);
        }
        sort(b.begin(),b.end());
        for (int i=0;i<k;++i){
            pq.push(b.back());
            b.pop_back();
        }
        int ans=0;
        for (int i=0;i<n;++i){
            ans+=pq.top(); pq.pop();
        }
        cout << ans << '\n';

    }
}