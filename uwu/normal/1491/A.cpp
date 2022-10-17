#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int cnt=0, arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i], cnt+=(arr[i]);
    for (int i=1;i<=q;++i){
        int op, x; cin >> op >> x;
        if (op==1){
            if (arr[x]==0) arr[x]=1, cnt++;
            else arr[x]=0, cnt--;
        }
        if (op==2){
            if (x>cnt) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
}