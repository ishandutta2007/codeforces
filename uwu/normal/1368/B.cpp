#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll n; cin >> n;
    ll tot=1;
    ll arr[10]={1,1,1,1,1,1,1,1,1,1};
    int idx=0;
    while (tot<n){
        tot/=arr[idx];
        arr[idx]++;
        tot*=arr[idx];
        idx++;
        if (idx==10) idx=0;
    }
    string uwu="codeforces";
    for (int i=0;i<=9;++i){
        for (int k=0;k<arr[i];++k) cout << uwu[i];
    }
    cout << '\n';
}