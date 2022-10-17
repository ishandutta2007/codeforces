#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+5;

int arr[MAXN], a[MAXN], b[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n; arr[n+1]=0;
        for (int i=1;i<=n;++i) cin >> arr[i], a[i]=b[i]=0;
        stack<int> q; q.push(0);
        for (int i=1;i<=n;++i){
            while (arr[q.top()]>=arr[i]) q.pop();
            a[i]=i-q.top();
            q.push(i);
        }
        while (!q.empty()) q.pop();
        q.push(n+1);
        for (int i=n;i>=1;--i){
            while (arr[q.top()]>=arr[i]) q.pop();
            a[i]+=q.top()-i-1;
            q.push(i);
        }
        for (int i=1;i<=n;++i) b[arr[i]]=min((b[arr[i]]==0?n:b[arr[i]]),a[i]);
        int temp=n;
        for (int i=1;i<=n;++i) temp=min(temp,b[i]), ans[n-i+1]=temp>=n-i+1;//, cout << b[i] << " ";
        // cout << '\n';
        for (int i=1;i<=n;++i) cout << ans[i];
        cout << '\n';
    }
}