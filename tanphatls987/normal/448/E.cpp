#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10,LIM=1e5;


ll imp[7000],x,k,t[N];
lli s[100];
int m;
vector <int> pri,g[7000];
void DFS(int pos){
    static ll cur=1;
//    cout<<pos<<" "<<cur<<'\n';
    if (pos==0){
        imp[++m]=cur;
        return;
    }
    FOR(i,0,s[pos].Y){
        DFS(pos-1);
        if (i<s[pos].Y) cur*=s[pos].X;
    }
    FOR(i,1,s[pos].Y) cur/=s[pos].X;
}
void decompose(ll x){
    int top=0;
    for(auto i:pri) {
        if (1LL*i*i>x) break;
        if (x%i==0){
            int c=0;
            while (x%i==0) x/=i,c++;
            s[++top]=lli(i,c);
        }
    }
    if (x>1) s[++top]=lli(x,1);
    DFS(top);
    sort(imp+1,imp+m+1);
    FOR(i,1,m)
        FOR(j,1,i) if (imp[i]%imp[j]==0) g[i].push_back(j);
}
void build(int x,int lv){
    static int top=0;
    if (x==1||lv==k){
        printf("%I64d ",imp[x]);
        top++;
        return;
    }
    for(auto i:g[x]) {
        if (top==LIM) break;
        build(i,lv+1);
    }
}
void prepare(){
    REP(i,2,N) if (!t[i]){
        pri.push_back(i);
        for(int j=i;j<N;j+=i) t[j]=i;
    }
    cin>>x>>k;
    decompose(x);
}
int main(){
    prepare();
    build(m,0);
}