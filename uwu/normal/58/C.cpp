#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int arr[MAXN], good[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i){
        int tmp=arr[i]-min(i-1,n-i);
        if (tmp>=1) good[tmp]++;
    }
    int ans=n;
    for (int i=1;i<MAXN;++i) ans=min(ans,n-good[i]);
    cout << ans << '\n';
}