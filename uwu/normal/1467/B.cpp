#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

int arr[MAXN], n;

int is(int i){
    if (i==1||i==n) return 0;
    return (arr[i+1]>arr[i]&&arr[i-1]>arr[i])||(arr[i+1]<arr[i]&&arr[i-1]<arr[i]);
}

int check(int i, int val){
    int tmp=val^arr[i];
    arr[i]^=tmp;
    int v1=is(i-1)+is(i)+is(i+1);
    arr[i]^=tmp;
    int v2=is(i-1)+is(i)+is(i+1);
    return v2-v1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;++i) cin >> arr[i];
        int rem=0, tot=0;
        for (int i=2;i<=n-1;++i) tot+=is(i);
        for (int i=2;i<=n-1;++i){
            for (int j=-1;j<=1;++j){
                rem=max(rem,check(i,arr[i-1]+j));
                rem=max(rem,check(i,arr[i+1]+j));
            }
        }
        cout << tot-rem << '\n';
    }
}