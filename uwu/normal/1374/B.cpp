#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll power(int x, int p){
    ll ans=1;
    for (int i=0;i<p;++i) ans*=x;
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int num2,num3; num2=num3=0;
        while (n%2==0) n/=2, num2++;
        while (n%3==0) n/=3, num3++;
        if (n!=1) cout << -1 << '\n';
        else if (num2>num3) cout << -1 << '\n';
        else{
            cout << 2*num3-num2 << '\n';
        }
    }
}