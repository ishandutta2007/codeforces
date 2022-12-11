#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=2e5+10;

int n,V,a[N],p[N],h[N],b[3][N];
vector <int> g[N];

void add(int T,int x,int v){
    while (x<=n){
        b[T][x]+=v;
        x+=x&-x;
    }
}
int get(int T,int x){
    int tmp=0;
    while (x){
        tmp+=b[T][x];
        x-=x&-x;
    }
    return tmp;
}
int findfre(int T,int v){
    int pos=0,ans;
    for(int i=1<<int(log2(n));i>0;i>>=1){
        int cur=pos+i;
        if (cur>n) continue;
        if (b[T][cur]==v) ans=cur;
        else if (b[T][cur]<v) v-=b[T][cur],pos=cur;
    }
    return ans;
}
void solve(){
    FOR(i,0,n-1) {
        h[i]=g[i].size();
        if (h[i]) add(i%3,i+1,1);
    }
    int top=0,last=-1;
    while (top<n){
        int v=get(top%3,last+2);
        //printf("%d %d %d\n",top,last+1,v);
        //FOR(i,1,n-1) cout<<h[i]<<" \n"[i==n-1];
        if (!v) {
            printf("Impossible");
            return;
        }
        int x=findfre(top%3,v)-1;
        while (h[x]){
            p[top++]=g[x][--h[x]];
            if (!h[x]) add(x%3,x+1,-1);
            x++;
        }
        last=a[p[top-1]];
    }
    printf("Possible\n");
    REP(i,0,n) printf("%d ",p[i]);
}
int main(){
    //OUTPUT;
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",a+i);
        g[a[i]].push_back(i);
    }
    solve();
}