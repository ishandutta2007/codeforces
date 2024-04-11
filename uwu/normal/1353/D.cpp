#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct uwu{
    int len,l,r;
};

bool cmp(uwu a, uwu b){
    return make_pair(a.len,b.l)<make_pair(b.len,a.l);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        priority_queue<uwu,vector<uwu>,function<bool(uwu,uwu)>> pq(cmp);
        pq.push({n,1,n});
        int cnt=0;
        while (!pq.empty()){
            uwu a=pq.top(); pq.pop();
            int mid=(a.l+a.r)/2;
            arr[mid]=++cnt;
            if (mid-1>=a.l) pq.push({mid-a.l,a.l,mid-1});
            if (mid+1<=a.r) pq.push({a.r-mid,mid+1,a.r}); 
        }
        for (int i=1;i<=n;++i){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
}