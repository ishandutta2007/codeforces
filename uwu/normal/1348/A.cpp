#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=31;

int owo[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    owo[0]=1; 
    for (int i=1;i<=30;++i){ owo[i] = owo[i-1]*2; }
    while (t--){
        int n; cin >> n;
        int ans=owo[n];
        for (int i=1;i<=(n-1)/2;++i){
            ans+=owo[i];
        }
        for (int i=(n/2);i<n;++i){
            ans-=owo[i];
        }
        cout << ans << '\n';
    }
}