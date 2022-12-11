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
const int MOD=1e9+7;
const int N=5e5+10;

int n,m,cur,link[N][2],tr[N];
int st[N];
string s,command;
void setlink(int x,int y){
    link[x][1]=y;
    link[y][0]=x;
}
void serase(int &cur,int L,int R){
    if (L>R) swap(L,R);
    while (L<=R){
        setlink(link[L][0],link[L][1]);
        L=link[L][1];
    }
    cur=L;
    if (cur>n) cur=link[cur][0];
}
void solve(){
    int x=link[0][1];
    while (x<=n){
        cout<<s[x-1];
        x=link[x][1];
    }
    ENDL;
}
void prepare(){
    cin>>n>>m>>cur>>s>>command;
    FOR(i,0,n) setlink(i,i+1);
    //
    int top=0;
    FOR(i,1,n) if (s[i-1]=='(') st[++top]=i;
    else{
        tr[i]=st[top];
        tr[st[top]]=i;
        top--;
    }
    //
    for(auto ch:command) {
        if (ch=='D') serase(cur,tr[cur],cur);
        else cur=link[cur][ch=='R'];
//        cout<<cur<<'\n';
//        solve();
    }
}

int main(){
//    freopen("input.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    solve();
}