#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e6+10;

int s[N],b[N],a[N],n,m,k,x,h[N]={0};
vector <int> E;
int add(int x,int v){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int findpos(int v){
    int pos=0,ans;
    for(int i=1<<int(log2(n));i;i>>=1){
        int cur=pos+i;
        if (cur>n) continue;
        if (b[cur]<v) pos=cur,v-=b[cur];
        else if (b[cur]==v) ans=cur;
    }
    return ans;
}
int main(){
    scanf("%d%d",&k,&m);
    FOR(i,1,m) scanf("%d",a+i);
    n=0;
    int rn=0;
    while (k--){
        scanf("%d",&x);
        if (x==-1) {
            int L=upper_bound(a+1,a+m+1,rn)-a-1;
            E.push_back(L);
            //printf("%d->%d\n",rn,L);
            rn-=L;
        }else s[++n]=x,rn++;
    }
    FOR(i,1,n) add(i,1),h[i]=1;
    for(auto i:E)
        FORD(j,i,1){
            int x=findpos(a[j]);
            h[x]=0;
            add(x,-1);
            //printf("%d %d\n",a[j],x);
        }
    if (count(h+1,h+n+1,0)==n) printf("Poor stack!");
    else FOR(i,1,n) if (h[i]) printf("%d",s[i]);
}