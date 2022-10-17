#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int a[MAXN],pos[MAXN],b[MAXN],freq[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i],pos[a[i]]=i;
    for (int i=1;i<=n;++i) cin >> b[i];
    int uwu;
    for (int i=1;i<=n;++i){
        uwu=pos[b[i]]-i;
        if (uwu>=0){
            freq[uwu]++;
        }
        else{
            freq[n+uwu]++;
        }
    }
    int ans=0;
    for (int i=0;i<=n;++i){
        ans=max(ans,freq[i]);
    }
    cout << ans << '\n';
}