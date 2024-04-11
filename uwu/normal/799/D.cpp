#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll n, a[MAXN];
struct Item{
    ll a, b;
    void fix(){ if (b>a) swap(a,b); }
    bool operator<(const Item &x) const{
        return make_pair(a,b)<make_pair(x.a,x.b);
    }
    bool enc(Item x){
        return a>=x.a&&b>=x.b;
    };
} s, e;
set<Item> last, curr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> e.a >> e.b >> s.a >> s.b >> n;
    s.fix(), e.fix();
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n,greater<ll>());
    if (s.enc(e)){ cout << 0 << '\n';  return 0;}
    curr.insert(s);
    for (int i=1;i<=n;++i){
        last.clear(), swap(last,curr);
        for (Item x:last){
            Item temp=x;
            if (x.a<e.a){
                temp.a*=a[i];
                temp.fix();
                if (temp.enc(e)){ cout << i << '\n'; return 0; }
                curr.insert(temp);
            }
            temp=x;
            temp.b*=a[i];
            temp.fix();
            if (temp.enc(e)){ cout << i << '\n'; return 0; }
            curr.insert(temp);
        }
    }
    cout << -1 << '\n';
}