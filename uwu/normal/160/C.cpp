#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll arr[MAXN];
map<ll,int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k; cin >> n >> k; k--;
    for (int i=0;i<n;++i) cin >> arr[i], cnt[arr[i]]++;
    sort(arr,arr+n);
    ll idx=k/n;
    while (idx!=0&&arr[idx-1]==arr[k/n]) idx--;
    k-=(idx)*n; k/=cnt[arr[idx]];
    cout << arr[idx] << " " << arr[k] << '\n';
}