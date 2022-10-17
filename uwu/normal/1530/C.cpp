#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        priority_queue<int,vector<int>,greater<int>> a;
        priority_queue<int> b;
        int ta=0, tb=0;
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            ta+=x;
            a.push(x);
        }
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            b.push(x);
        }
        while (a.size()>n-n/4) ta-=a.top(), a.pop();
        int szb=0;
        for (int i=1;i<=n-n/4;++i){
            szb++;
            tb+=b.top(); b.pop();
        }
        int ans=n;
        while (ta<tb){
            ans++;
            ta+=100;
            a.push(100);
            b.push(0);
            while (a.size()>ans-ans/4){
                ta-=a.top(), a.pop();
            }
            while (szb<ans-ans/4){
                tb+=b.top(); b.pop(); szb++;
            }
        }
        cout << ans-n << '\n';
    }
}