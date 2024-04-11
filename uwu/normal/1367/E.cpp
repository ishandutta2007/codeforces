#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int freq[26],cnt[2001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ms(freq,0); ms(cnt,0);
        int n,k; cin >> n >> k;
        string uwu; cin >> uwu;
        for (char x:uwu) freq[x-'a']++;
        for (int i=1;i<=2000;++i){
            for (int x:freq) cnt[i]+=x/i; 
        }
        int ans=0;
        for (int sz=1;sz<=n;++sz){
            for (int i=1;i<=sz;++i){
                if (k%i!=0||sz%i!=0) continue;
                if (cnt[sz/i]>=i) ans=max(ans,sz);
            }
        }
        cout << ans << '\n';
    }
}