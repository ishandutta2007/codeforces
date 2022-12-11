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
const int N=1e6+10,maxbit=30;

int n,k,a[N];
struct trie{
    trie *h[2];
    int v;
    trie(){
        FOR(i,0,1) h[i]=NULL;
        v=0;
    }
};
trie* root;
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) a[i]^=a[i-1];
}
ll solve(){
    root=new trie();
    k--;
    ll ans=0;
    FOR(i,0,n){
        trie* cur=root;
        FORD(lv,maxbit-1,0){
            int type=k&(1<<lv);
            int x=(a[i]&(1<<lv))>0;
            if (type){
                if (cur->h[x^1]==NULL) break;
                cur=cur->h[x^1];
            }else {
                if (cur->h[x^1]!=NULL) ans+=cur->h[x^1]->v;
                if (cur->h[x]==NULL) break;
                cur=cur->h[x];
            }
        }
        cur=root;
        FORD(lv,maxbit-1,0){
            int x=(a[i]&(1<<lv))>0;
            if (cur->h[x]==NULL) cur->h[x]=new trie();
            cur=cur->h[x];
            cur->v++;
        }
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}