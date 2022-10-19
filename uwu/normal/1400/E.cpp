#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;

int arr[MAXN];

int solve(int l, int r){
    int small=arr[l],cnt=0;
    for (int i=l;i<=r;++i){
        if (arr[i]<small) cnt=1, small=arr[i];
        else if (arr[i]==small) cnt++;
    }
    int owo=0;
    for (int i=l;i<=r;++i) arr[i]-=small;
    owo+=small;
    int p=l;
    for (int i=l;i<=r;++i){
        if (arr[i]!=0) continue;
        if (p<=i-1) owo+=solve(p,i-1);
        p=i+1;
    }
    if (p<=r) owo+=solve(p,r);
    return min(owo,r-l+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    cout << solve(1,n) << '\n';
}