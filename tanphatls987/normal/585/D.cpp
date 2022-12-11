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
const int N=30;
const int cho[3][2]={{0,1},{0,2},{1,2}};
const char ch[3]={'L','M','W'};

int n,a[N][3],p3[N],d[3];
struct way{
    int d1,d2,code,val;
    way (int _d1=0,int _d2=0,int _code=0,int _val=0){
        d1=_d1;d2=_d2;code=_code;val=_val;
    }
}b[2][2000000];
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
bool comp(way a,way b){
    return (a.d1==b.d1)?a.d2<b.d2:a.d1<b.d1;
}
bool operator ==(way a,way b){
    return a.d1==b.d1&&a.d2==b.d2;
}
void prepare(){
    cin>>n;
    REP(i,0,n)
        REP(j,0,3) cin>>a[i][j];
    p3[0]=1;
    FOR(i,1,n) p3[i]=p3[i-1]*3;
}
void solve(){
    int n1=n/2;
    REP(i,0,p3[n1]){
        memset(d,0,sizeof(d));
        int cur=i;
        REP(j,0,n1){
            int sel=cur%3;
            for(auto idx:cho[sel]) d[idx]+=a[j][idx];
            cur/=3;
        }
//        printf("%d %d %d %d\n",i,d[0],d[1],d[2]);
        b[0][i]=way(d[0]-d[1],d[0]-d[2],i,d[0]);
    }
    REP(i,0,p3[n-n1]){
        memset(d,0,sizeof(d));
        int cur=i;
        REP(j,0,n-n1){
            int sel=cur%3;
            for(auto idx:cho[sel]) d[idx]+=a[n1+j][idx];
            cur/=3;
        }
//        printf("%d %d %d %d\n",i,d[0],d[1],d[2]);
        b[1][i]=way(-(d[0]-d[1]),-(d[0]-d[2]),i,d[0]);
    }
    sort(b[1],b[1]+p3[n-n1],comp);
    int n2=0;
    REP(i,0,p3[n-n1]){
        b[1][n2]=b[1][i];
        while (i<p3[n-n1]-1&&b[1][i+1]==b[1][n2]){
            i++;
            if (maximize(b[1][n2].val,b[1][i].val)) b[1][n2].code=b[1][i].code;
        }
        n2++;
    }
    int ans=-inf,idx1,idx2;
    REP(i,0,p3[n1]){
        int idx=lower_bound(b[1],b[1]+n2,b[0][i],comp)-b[1];
        if (b[0][i]==b[1][idx]){
            if (maximize(ans,b[0][i].val+b[1][idx].val)) idx1=b[0][i].code,idx2=b[1][idx].code;
        }
    }
    if (ans==-inf) {
        printf("Impossible");
        return;
    }
//    cout<<ans<<" "<<idx1<<" "<<idx2<<'\n';
    FOR(i,1,n1){
        int sel=idx1%3;
        for(auto idx:cho[sel]) printf("%c",ch[idx]);
        idx1/=3;
        ENDL;
    }
    FOR(i,1,n-n1){
        int sel=idx2%3;
        for(auto idx:cho[sel]) printf("%c",ch[idx]);
        idx2/=3;
        ENDL;
    }
}
int main(){
    prepare();
    solve();
}