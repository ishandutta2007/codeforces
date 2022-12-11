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
const int N=2e3+10;

int n,k,x,y,v[N],h[N]={0},p[N];
vector <int> a[N];
bool comp(int a,int b){
    return v[a]<v[b];
}
void prepare(){
    scanf("%d%d",&k,&n);
    FOR(i,1,n) scanf("%d",&v[i]);
    FOR(i,1,n-1){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    //FOR(i,1,n) printf("%d ",p[i]);
}
int DFS(int L,int R,int par,int x){
    if (v[x]<L||v[x]>R||h[x]==1) return 0;
    int tmp=1;
    for(auto &i:a[x]) if (i!=par) tmp=(1LL*tmp*(DFS(L,R,x,i)+1))%MOD;
    //printf("%d %d %d %d\n",L,R,x,tmp);
    return tmp;
}
int main(){
    prepare();
    int ans=0;
    FOR(i,1,n) ans=(ans+DFS(v[p[i]],v[p[i]]+k,0,p[i]))%MOD,h[p[i]]=1;
        //printf("%d %d\n",i,ans);
    cout<<ans;
}