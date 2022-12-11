#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
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

struct pact{
    int x,y,k,id;
};
pact p[N],a[N];
int b[N]={0},n,m,k,ans[N],bar,s[N];
vector <int> st[N];
bool comp(pact a,pact b){
    if (a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}
int get(int x){
    int tmp=0;
    while (x){
        tmp+=b[x];
        x-=x&-x;
    }
    return tmp;
}
void add(int x,int v){
    while (x<=k){
        b[x]+=v;
        x+=x&-x;
    }
}
int findfre(int v){
    int ans=0,pos=0;
    for(int i=bar;i>0;i>>=1){
        int cur=pos+i;
        if (cur>k) continue;
        if (v>b[cur]) pos=cur,v-=b[pos];
        else if (v==b[cur]) ans=cur;
    }
    return ans;
}
void prepare(){
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].k);
        a[i].id=i;
        s[i]=a[i].x;
    }
    sort(p+1,p+m+1,comp);
    sort(a+1,a+n+1,comp);
    sort(s+1,s+n+1);
    k=0;
    FOR(i,1,n){
        s[++k]=s[i];
        while (i<n&&s[i+1]==s[i]) i++;
    }
    bar=1<<(int(log2(k)));
    //FOR(i,1,n) printf("%d %d %d\n",a[i].x,a[i].y,a[i].k);
}
void solve(){
    int top=1;
    //printf("%d %d\n",top,n);
    FOR(i,1,m){
        while (top<=n&&a[top].y>=p[i].y){
            int x=lower_bound(s+1,s+k+1,a[top].x)-s;
            //printf("%d %d\n",top,x);
            add(x,1);
            st[x].push_back(top);
            top++;
        }
        int pos=upper_bound(s+1,s+k+1,p[i].x)-s-1;
        if (!pos){
            printf("NO");
            return;
        }
        int v=get(pos);
        //printf("tick");
        if (!v){
            printf("NO");
            return;
        }
        //printf("%d %d\n",pos,v);
        int rp=findfre(v),sel=st[rp].back();

        ans[p[i].id]=a[sel].id;
        a[sel].k--;
        if (a[sel].k==0) {
            st[rp].pop_back();
            add(rp,-1);
        }
    }
    printf("YES\n");
    FOR(i,1,m) printf("%d ",ans[i]);
}
int main(){
    prepare();
    solve();
}