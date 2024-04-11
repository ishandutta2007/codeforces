#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
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

int n,m,h[N],lv[N],w[N],f[N]={0},t[N];
ii e[N];
vector <int> a[N];
bool maximize(int &a,int b){
    if (a<b) a=b;else return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,m){
        scanf("%d%d%d",&e[i].X,&e[i].Y,w+i);
        a[e[i].X].push_back(i);
        a[e[i].Y].push_back(i);
    }
    queue <int> q;
    q.push(1);
    lv[1]=1;
    memset(f,-1,sizeof(f));
    f[1]=0;
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto i:a[x]){
            int y=x^e[i].X^e[i].Y;
            if (lv[y]&&lv[y]!=lv[x]+1) continue;
            if (!lv[y]) q.push(y);
            lv[y]=lv[x]+1;
            if (maximize(f[y],f[x]+w[i])) t[y]=i;
        }
    }
    printf("%d\n",lv[n]-1-2*f[n]+count(w,w+m,1));
    for(int i=1,x=n;i<lv[n];i++){
        int ed=t[x];
        if (!w[ed]) printf("%d %d 1\n",e[ed].X,e[ed].Y);
        h[ed]=1;
        x^=e[ed].X^e[ed].Y;
        //printf("%d %d\n",i,x);
    }
    REP(i,0,m) if (!h[i]&&w[i]) printf("%d %d 0\n",e[i].X,e[i].Y);
}