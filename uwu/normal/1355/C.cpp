#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+10;

ll pre1[MAXN];
ll pre2[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int a,b,c,d; cin >> a >> b >> c >> d;
    for (int i=1;i<MAXN;++i){
        pre1[i]=pre1[i-1]+(c<=i && i<=d);
        pre2[i]=pre2[i-1]+pre1[i];
    }
    ll ans=0;
    for (int i=a;i<=b;++i){
        ans+=pre2[i+c-1]-pre2[i+b-2];
    }
    cout << ans << '\n';
}