#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define mt make_tuple

const int MN = 1e5+5, MM = 2e6+6, mod = 1e9+9;
int n, m, i, j, hsh[MM], pw[MM]={1};
string s; set<int> used;
inline int gethsh(int x,int y){
    int ret=(hsh[y]-1LL*hsh[x-1]*pw[y-x+1])%mod;
    return ret<0?ret+mod:ret;
}

struct SuffixAutomaton{
    map<char,int> nxt[MM];
    int len[MM], link[MM]={-1}, cnt[MM], lst, cnter;
    void extend(char ch){
        int cur = ++cnter;
        cnt[cur] = 1;
        len[cur] = len[lst]+1;
        while(lst>=0&&!nxt[lst].count(ch)){
            nxt[lst][ch] = cur;
            lst = link[lst];
        }
        if(~lst){
            int ot = nxt[lst][ch];
            if(len[ot]!=len[lst]+1){
                int split = ++cnter;
                len[split] = len[lst]+1;
                nxt[split] = nxt[ot];
                link[split] = link[ot];
                link[ot] = split;
                while(lst>=0&&nxt[lst].count(ch)&&nxt[lst][ch]==ot){
                    nxt[lst][ch] = split;
                    lst = link[lst];
                }
                ot = split;
            }
            link[cur] = ot;
        }
        else link[cur] = 0;
        lst = cur;
    }
}sa;

int main(){
    cin >> s;
    for(char c : s)
        sa.extend(c);
    vi ord;
    for(i=1;i<=sa.cnter;i++)
        ord.pb(i);
    sort(ord.begin(),ord.end(),[](int i,int j){return sa.len[i]>sa.len[j];});
    for(auto v : ord)
        sa.cnt[sa.link[v]]+=sa.cnt[v];
    for(i=1;i<MM;i++)
        pw[i]=133LL*pw[i-1]%mod;
    for(scanf("%d",&n),i=1;i<=n;i++){
        cin >> s; m = (int)s.size();
        for(j=0;j+1<m;j++)
            s += s[j];
        for(j=0;j<(int)s.size();j++)
            hsh[j+1]=(133LL*hsh[j]+s[j]-'a'+1)%mod;
        int x=0, len=0; ll ans=0;
        used.clear();
        for(j=0;j<(int)s.size();j++){
            while(!sa.nxt[x].count(s[j])&&x) x=sa.link[x], len=sa.len[x];
            if(sa.nxt[x].count(s[j])) x=sa.nxt[x][s[j]], len++;
            while(~sa.link[x]&&sa.len[sa.link[x]]>=m) x=sa.link[x], len=sa.len[x];
            if(j>=m-1){
                int hh = gethsh(j-m+2,j+1);
                if(used.count(hh)) continue;
                used.insert(hh);
                if(len>=m) ans += sa.cnt[x];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}