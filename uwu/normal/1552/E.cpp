#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101, MAXK=101;
const int MAXM=MAXN*MAXK;

int a[MAXM], cnt[MAXM], ansl[MAXN], ansr[MAXN];
int seen[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int lim=(n+k-2)/(k-1);
    int l=1;
    for (int i=1;i<=n*k;++i){
        cin >> a[i];
        if (ansl[a[i]]) continue;
        if (seen[a[i]]>=l){
            int pl=seen[a[i]], pr=i;
            for (int j=pl;j<=pr;++j){
                cnt[j]++;
                if (cnt[j]==lim) l=max(l,j+1);
            }
            ansl[a[i]]=pl, ansr[a[i]]=pr;
        }
        else seen[a[i]]=i;
    }
    for (int i=1;i<=n;++i) cout << ansl[i] << " " << ansr[i] << '\n';
}