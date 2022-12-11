#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

stack <int> s;
int n,m,ans,low[N],num[N],h[N]={0},t[N]={0};
vector <int> a[N],b[N];
void DFSt(int x){
    static int c=0;
    s.push(x);
    num[x]=low[x]=--c;
    for(vector <int>::iterator i=a[x].begin();i!=a[x].end();i++){
        int nx=*i;
        if (num[nx]>0) continue;
        if (!num[nx]) DFSt(nx);
        low[x]=max(low[x],low[nx]);
    }
    if (low[x]<=num[x]){
        num[x]=++m;
        t[m]=1;
        while (s.top()!=x){
            num[s.top()]=m;
            s.pop();
            t[m]++;
        }
        s.pop();
    }
}
int main(){
    scanf("%d%d",&n,&m);
    ans=0;
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
    }
    m=0;
    FOR(i,1,n) if (!num[i]) DFSt(i);
    FOR(x,1,n)
        for(auto y:a[x]) if (num[x]!=num[y]){
            b[num[x]].push_back(num[y]);
            b[num[y]].push_back(num[x]);
        }
    queue <int> q;
    FOR(x,1,m) if (!h[x]){
        int c=t[x],ok=(t[x]>1);
        q.push(x);
        h[x]=1;
        while (!q.empty()){
            int cx=q.front();q.pop();
            for(auto i:b[cx]) if (!h[i]){
                h[i]=1;c+=t[i];
                q.push(i);
                ok|=(t[i]>1);
            }
        }
        ans+=c-1+ok;
    }
    cout<<ans;
}