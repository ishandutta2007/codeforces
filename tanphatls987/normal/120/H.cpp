#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("input.txt","r",stdin)
#define OUTPUT freopen("output.txt","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e2+10,M=6e5;

int n,match[M],ans[N],h[M],T=0,cur=0,c=0,p[N];
string s;
vector <int> a[N];
void DP(int pos,int x){
    if (x==-1){
        if (c) a[pos].push_back(cur);
        int tmp=cur;
        //printf("%d %d ",c,tmp);
        //while (tmp) printf("%c",'a'-1+tmp%27),tmp/=27;
        //printf("%d\n",cur);
        //ENDL;
        return;
    }
    if (c<4){
        c++;cur=cur*27+(s[x]-'a'+1);
        DP(pos,x-1);
        c--;cur=(cur-(s[x]-'a'+1))/27;
    }
    DP(pos,x-1);
}
bool DFS(int x){
    for(auto y:a[x]) if (h[y]!=T){
        h[y]=T;
        bool ok=false;
        if (match[y]) ok=DFS(match[y]);
        else ok=true;
        if (ok){
            ans[x]=y;
            match[y]=x;
            return true;
        }
    }
    return false;
}
int main(){
    INPUT;OUTPUT;
    cin>>n;
    FOR(i,1,n){
        cin>>s;
        DP(i,s.length()-1);
    }
    FOR(i,1,n) p[i]=i;
    int top=n;
    while (69){
        T++;
        int old=top;
        FORD(i,top,1) if (DFS(p[i])) swap(p[i--],p[top--]);
        if (old==top) break;
    }
    if (top) printf("-1");else
    FOR(i,1,n){
        while (ans[i]) printf("%c",'a'-1+ans[i]%27),ans[i]/=27;
        ENDL;
    }
}