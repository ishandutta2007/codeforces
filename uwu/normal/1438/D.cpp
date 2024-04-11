#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int a[MAXN];
struct Item{
    int i, j, k;
    void print(){
        cout << i << " " << j << " " << k << '\n';
    }
}; vector<Item> ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int tot=0, pos=0;
    for (int i=1;i<=n;++i){
        cin >> a[i]; tot^=a[i];
    }
    if (n%2==0&&tot!=0){ cout << "NO" << '\n'; return 0; }
    cout << "YES" << '\n';
    if (n%2==0) n--;
    for (int i=3;i<=n;i+=2) ans.push_back({i-2, i-1, i});
    for (int i=1;i+1<n;i+=2) ans.push_back({i, i+1, n});
    cout << ans.size() << '\n';
    for (Item x:ans) x.print();
}