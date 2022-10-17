#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

struct Item{ int t, x, y, p; }; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r, n; cin >> r >> n;
    int best=-0x3f3f3f3f;
    deque<Item> q; q.push_back({0,1,1,0});
    for (int i=1,t,x,y,p;i<=n;++i){
        cin >> t >> x >> y;
        while (!q.empty() && t>=q.front().t+2*r){
            best=max(best,q.front().p);
            q.pop_front();
        }
        p=best+1;
        for (Item aa:q){
            if (t-aa.t>=abs(x-aa.x)+abs(y-aa.y)) p=max(p,aa.p+1);
        }
        q.push_back({t,x,y,p});
    }
    for (Item aa:q) best=max(best,aa.p);
    cout << best << '\n';
}