#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,st[8],h[2];
multiset <int> mse;
void prepare(){
    scanf("%d",&n);
    FOR(i,0,2) scanf("%d",st+i);
    FOR(i,1,n) {
        int x;
        scanf("%d",&x);
        if (x>st[0]+st[1]+st[2]){
            printf("-1");
            exit(0);
        }
        mse.insert(x);
    }
}
bool comp(int x,int y){
    return st[x]<st[y];
}
int solve(){
    int ans=0;
    sort(st,st+3);
    while (1){
        auto idx=mse.upper_bound(st[1]+st[2]);
        if (idx!=mse.end()){
            mse.erase(idx);
            ans++;
        }else break;
    }
    while (1){
        auto idx=mse.upper_bound(st[0]+st[2]);
        if (idx!=mse.end()){
            mse.erase(idx);
            ans++;
            idx=mse.upper_bound(st[0]);
            if (idx!=mse.begin()) mse.erase(--idx);
        }else break;
    }
    int bar=max(st[0]+st[1],st[2]);
    while (1){
        auto idx=mse.upper_bound(bar);
        if (idx!=mse.end()){
            mse.erase(idx);
            ans++;
            idx=mse.upper_bound(st[1]);
            if (idx!=mse.begin()) mse.erase(--idx);
        }else break;
    }
    if (st[0]+st[1]>st[2]){
        while (1){
            auto idx=mse.upper_bound(st[2]);
            if (idx!=mse.end()){
                mse.erase(idx);
                ans++;
                idx=mse.upper_bound(st[2]);
                if (idx!=mse.begin()) mse.erase(--idx);
            }else break;
        }
    }
    while (!mse.empty()){
        ++ans;
        auto idx=mse.end();
        mse.erase(--idx);
        FOR(i,0,1){
            idx=mse.upper_bound(st[i]);
            if (idx!=mse.begin()){
                h[i]=1;
                mse.erase(--idx);
            }else h[i]=0;
        }
        if (h[0]+h[1]==0){
            auto idx=mse.upper_bound(st[0]+st[1]);
            if (idx!=mse.begin()) mse.erase(--idx);
        }
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}