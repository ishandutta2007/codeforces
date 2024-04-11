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

const ll inf=1e12;
const int MOD=1e9+7;
const int N=1e5+1;


int n1,n2,W,a[N],p[N],p10[6],b[N],t[N];
ii ma[N];
vector <int> v[N];
void add(int x,int v){
    while (x<N){
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
bool operator <(ii x,ii y){
    return 1LL*x.X*y.Y<1LL*x.Y*y.X;
}
bool operator ==(ii x,ii y){
    return !(x<y)&&!(y<x);
}
bool comp(int x,int y){
    if (ii(x,a[x])==ii(y,a[y])) return x<y;
    return (ii(x,a[x])<ii(y,a[y]));
}
int rev(int x,int y){
    int ans=0;
    FORD(i,y,0) ans+=p10[i]*(x%10),x/=10;
    return ans;
}
bool cmp(ii x,ii y){
    return x<y;
}
int main(){
    //INPUT;OUTPUT;
    scanf("%d%d%d",&n1,&n2,&W);
    p10[0]=1;
    FOR(i,1,5) p10[i]=p10[i-1]*10;
    a[N-1]=1;
    REP(i,0,5)
        REP(j,p10[i],p10[i+1]) a[j]=rev(j,i);
    REP(i,1,N) p[i]=i;
    sort(p+1,p+N,comp);
    int m=0;
    REP(i,1,N){
        int j=i;
        while (j<N-1&&ii(p[j+1],a[p[j+1]])==ii(p[i],a[p[i]])) j++;
        ma[++m]=ii(p[i],a[p[i]]);
        //printf("%d %d\n",p[i],a[p[i]]);
        FOR(k,i,j) t[p[k]]=m,v[m].push_back(p[k]);
        i=j;
    }
//    for(auto i:v[t[12]]) printf("%d ",i);ENDL;
    ll ansx=n1+1,ansy=n2+1;
    FOR(i,1,n1){
        int idx=lower_bound(ma+1,ma+m+1,ii(a[i],i),cmp)-ma;
//        printf("%d %d %d %d\n",ma[idx].X,ma[idx].Y,a[i],i);
        if (ma[idx]==ii(a[i],i)) for(auto j:v[idx]) add(j,1);
        int L=1,R=n2;
        while (L<=R){
            int M=(L+R)/2;
            if (get(M)>=W) R=M-1;
            else L=M+1;
            //printf("%d %d %d\n",i,M,get(M));
        }
        if (L<=n2&&1LL*i*L<ansx*ansy) ansx=i,ansy=L;
    }
    if (ansx>n1) printf("-1");
    else cout<<ansx<<" "<<ansy;

}