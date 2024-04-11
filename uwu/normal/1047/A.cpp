#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    if (n%3==0){
        cout << 1 << " " << 1 << " " << n-2 << '\n';
    }
    if (n%3==1){
        cout << 1 << " " << 2 << " " << n-3 << '\n';
    }
    if (n%3==2){
        cout << 1 << " " << 2 << " " << n-3 << '\n';
    }
}