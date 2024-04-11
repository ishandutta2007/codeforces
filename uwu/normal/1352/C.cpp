#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        int uwu=k/(n-1);
        int owo=k%(n-1);
        if (owo==0) owo=-1;
        //cout << uwu << " " << owo << '\n';
        cout << uwu*n + owo << '\n';
    }
}