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
const int N=2e5+10;

int a[N],b[N],n,m,cap[N],cur[N]={0},x,key,v,nextp,last;
void update(int k,int x,int v){
    if (k==1){
        while (x){
            b[x]=min(b[x],v);
            x-=x&-x;
        }
        return;
    }
    while (x<=n){
        a[x]=max(a[x],v);
        x+=x&-x;
    }
}
int get(int k,int x){
    if (k==1){
        int tmp=n+1;
        while (x<=n){
            tmp=min(b[x],tmp);
            x+=x&-x;
        }
        return tmp;
    }
    int tmp=0;
    while (x){
        tmp=max(a[x],tmp);
        x-=x&-x;
    }
    return tmp;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",cap+i);
    scanf("%d",&m);
    FOR(i,1,n) a[i]=i+1,b[i]=i-1;
}
void DFS(int idx,int v){
    //printf("%d %d\n",idx,v);
    if (idx==n+1) {nextp=n+1;return;}
    update(1,idx,last);
    cur[idx]+=v;
    if (cur[idx]>=cap[idx]) {
        v=cur[idx]-cap[idx],cur[idx]=cap[idx];
        DFS(get(0,idx),v);
        update(0,idx,nextp);
    }else nextp=idx;
}
int main(){
    prepare();
    while (m--){
        scanf("%d%d",&key,&x);
        if (key==1){
            last=get(1,x);
            scanf("%d",&v);
            DFS(x,v);
        }else printf("%d\n",cur[x]);
    }
}