#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define at(x,idx) (1&(x>>idx))
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1, L=30;

int arr[MAXN], n;
unordered_map<int,ll> m;

ll cnt(int x, int a){
    m.clear();
    ll ret=0;
    for (int i=1;i<=n;++i){
        if (at(arr[i],x)^a) m[arr[i]>>(x+1)]++;
        else ret+=m[arr[i]>>(x+1)];
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    ll tot=0,ans=0;
    for (int x=L;x>=0;--x){
        ll xor0=cnt(x,0);
        ll xor1=cnt(x,1);
        ans<<=1;
        if (xor0<=xor1) tot+=xor0; 
        else ans+=1, tot+=xor1;
    }
    cout << tot << " " << ans << '\n';
    
}