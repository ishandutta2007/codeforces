#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=6e3+10;

int n,x,y,p[N],s[N],f[N],top,ans;
vector <int> a[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i);
    FOR(i,1,n-1) {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
bool maximize(int &a,int b){
    if (a<b) a=b;else return false;
    return true;
}
void DFS(int par,int x){
    maximize(ans,top);
    for(auto &i:a[x]) if (i!=par){
        int L=1,R=top;
        while (L<=R){
            int M=(L+R)>>1;
            if (p[i]>s[M]) L=M+1;
            else R=M-1;
        }
        ii tmp=ii(L,s[L]);
        int ltop=top;
        s[L]=p[i];
        if (L>top) top++;
        //printf("%d %d %d\n",i,L,top);
        DFS(x,i);
        s[tmp.X]=tmp.Y;
        top=ltop;
    }
}
void solve(){
    ans=0;
    FOR(i,1,n){
        //printf("%d\n",i);
        f[i]=1;top=1;
        s[1]=p[i];
        DFS(0,i);
    }
    cout<<ans;
}
int main(){
    prepare();
    solve();
}