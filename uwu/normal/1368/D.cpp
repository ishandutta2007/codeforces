#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

ll arr[MAXN];
int cnt[20];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        for (int k=0;k<20;++k) if (1&(arr[i]>>k)) cnt[k]++;
    }
    ll ans=0,temp; bool flag=true;
    while (flag){
        flag=false; temp=0;
        for (int i=0;i<20;++i) if (cnt[i]) flag=true, temp+=(1<<i), cnt[i]--;
        ans+=temp*temp;
    }
    cout << ans << '\n';
}