#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7,alp=26;
const int N=1e4+10,M=1e5+10;

int n,m,t[N];
string s,s1[M];
int cv(char ch){
    if (ch>='A'&&ch<='Z') return ch-'A';
    return ch-'a';
}
struct trie{
    trie *h[alp];
    int x;
    trie (){
        REP(i,0,alp) h[i]=NULL;
        x=0;
    }
};
trie *root;
void prepare(){
    cin>>n>>s>>m;
    root=new trie();
    FOR(i,1,m) {
        cin>>s1[i];
        int n1=s1[i].length();
        trie *cur=root;
        FORD(j,n1-1,0){
            int ch=cv(s1[i][j]);
            if (cur->h[ch]==NULL) cur->h[ch]=new trie();
            cur=cur->h[ch];
        }
        cur->x=i;
    }
}
void solve(){
    t[n]=-1;
    FORD(i,n-1,0){
        trie *cur=root;
        for(int j=i;j<n;j++){
            int ch=s[j]-'a';
            if (cur->h[ch]==NULL) break;
            cur=cur->h[ch];
            if (cur->x&&t[j+1]){
                t[i]=cur->x;
                break;
            }
        }
    }
    int cur=0;
    assert(t[0]);
    while (cur<n){
        cout<<s1[t[cur]]<<" ";
        cur+=int(s1[t[cur]].length());
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}