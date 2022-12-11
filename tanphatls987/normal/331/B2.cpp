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
const int N=3e5+10;

int n,m,p[N],pos[N],b[N],cur[N];
void add(int x,int v){
    if (!v) return;
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",p+i);
        pos[p[i]]=i;
    }
    FOR(i,1,n) {
        cur[i]=pos[i]<pos[i-1];
        add(i,cur[i]);
    }
    scanf("%d",&m);
    while (m--){
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        if (type==1) printf("%d\n",get(y)-get(x)+1);
        else {
            x=p[x],y=p[y];
            swap(p[pos[x]],p[pos[y]]);
            add(x,-cur[x]);add(y,-cur[y]);
            swap(pos[x],pos[y]);
            cur[x]=pos[x]<pos[x-1];
            cur[y]=pos[y]<pos[y-1];
            add(x,cur[x]);add(y,cur[y]);
            if (x<n||cur[x+1]!=(pos[x+1]<pos[x])){
                add(x+1,-cur[x+1]+(pos[x+1]<pos[x]));
                cur[x+1]=(pos[x+1]<pos[x]);
            }
            if (y<n||cur[y+1]!=(pos[y+1]<pos[y])){
                add(y+1,-cur[y+1]+(pos[y+1]<pos[y]));
                cur[y+1]=(pos[y+1]<pos[y]);
            }
        }
//        FOR(i,1,n) cout<<pos[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<p[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<cur[i]<<" \n"[i==n];
    }
}