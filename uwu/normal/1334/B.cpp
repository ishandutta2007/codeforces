#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,k; cin >> n >> k;
        priority_queue<int> pq; ll total=0, ans=0;
        for (int i=0,a;i<n;++i){
            cin >> a;
            if (a>=k){
                total+=a; ans++;
            }
            else if (a<k){
                pq.push(a);
            }
        }
        while (!pq.empty()){
            if (total+pq.top()>=k*(ans+1)){
                total+=pq.top(); pq.pop(); ans++;
            }else{break;}
        }
        cout << ans << '\n';
    }
}