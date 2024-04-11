#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+10;

int n, arr[MAXN], cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;++i) cnt[i]=0;
        for (int i=1;i<=n;++i) cin >> arr[i], cnt[arr[i]]++;
        int best=0,tot=0;
        for (int i=1;i<=n;++i){
            if (cnt[i]>best) best=cnt[i],tot=1;
            else if (cnt[i]==best) tot++;
        }
        cout << (n-tot-best+1)/(best-1) << '\n';
    }
}