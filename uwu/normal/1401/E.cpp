#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6;

struct vert{
    int x,l,r,val;
    bool operator<(vert a){
        return x<a.x;
    }
};
struct Event{
    int x,h,c,val; // 0 in, 1 out.
    bool operator<(Event a){
        return make_pair(x,c)<make_pair(a.x,a.c);
    }
};
vector<Event> e;
vector<vert> uwu;
int bit[MAXN+1];
ll ans=0;

void Insert(int idx, int val){
    for (int i=idx;i<=MAXN;i+=i&-i) bit[i]+=val;
}

int Query(int idx){
    int ret=0;
    for (int i=idx;i>0;i-=i&-i) ret+=bit[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=1,a,b,c;i<=n;++i){
        cin >> a >> b >> c;
        if (b==0&&c==MAXN) ans++;
        e.push_back({b,a,0,1+(b==0&&c==MAXN)});
        e.push_back({c,a,1,1+(b==0&&c==MAXN)});
    }
    sort(e.begin(),e.end());
    for (int i=1,a,b,c;i<=m;++i){
        cin >> a >> b >> c;
        if (b==0&&c==MAXN) ans++;
        uwu.push_back({a,b,c,1+(b==0&&c==MAXN)});
    }
    sort(uwu.begin(),uwu.end());
    int p=0;
    for (vert curr:uwu){
        int x=curr.x,l=curr.l,r=curr.r;
        while (p!=2*n&&(e[p].x<x||(e[p].x<=x&&(e[p].c==0)))){
            if (e[p].c==0) Insert(e[p].h,1);
            else Insert(e[p].h,-1);
            p++;
        }
        ans+=(Query(r)-Query(l-1));
    }
    cout << ans+1 << '\n';
}