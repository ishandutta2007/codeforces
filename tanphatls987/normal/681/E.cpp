 #include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> pd;

const ll inf=4e9;
const int MOD=1e9+7;
const int N=2e5+10;
const double PI=atan(1)*4;
const double eps=1e-16;

int h[N<<1];
double p[N<<1];
vector <pd> a;
struct circle{
    int x,y;
    ll rad;
    circle (int _x=0,int _y=0,ll _rad=0){
        x=_x;y=_y;rad=_rad;
    }
};
ll sqr(ll x){return x*x;}

void addpair(double L,double R){
//    printf("%.6f %.6f\n",L,R);
    if (L<-eps) {
        addpair(L+2*PI,R+2*PI);
        return;
    }
    if (R>2*PI+eps){
        addpair(L,2*PI);
        addpair(0,R-2*PI);
        return;
    }
    a.push_back(pd(max(.0,L),R));
}
double unitangle(int x,int y){
    if (y<0) return PI+unitangle(-x,-y);
    if (x<0) return PI/2+unitangle(y,-x);
    return atan((y+.0)/x);
}
void coverangle(circle a,circle b){

    ll sqrdist=sqr(a.x-b.x)+sqr(a.y-b.y);
    double dist=sqrt(sqrdist);
    ///special case when b cover (a.x,a.y)
    if (dist<=b.rad+eps){
        printf("1.0");
        exit(0);
    }
    if (dist>=a.rad+b.rad+eps) return;
    double piv=unitangle(b.x-a.x,b.y-a.y);
    double angle;
    if (dist<=a.rad+eps) angle=PI/2-acos((b.rad+.0)/dist);
    else angle=acos((1LL*a.rad*a.rad+sqrdist-1LL*b.rad*b.rad+.0)/(2*dist*a.rad));
    double L=piv-angle,R=piv+angle;
    addpair(L,R);
}
void prepare(){
    int v,wtime;
    circle cen;
    scanf("%d%d%d%d",&cen.x,&cen.y,&v,&wtime);
    cen.rad=min(inf,1LL*v*wtime);
    int n;
    scanf("%d",&n);
    while (n--){
        int x,y,rad;
        scanf("%d%d%d",&x,&y,&rad);
        coverangle(cen,circle(x,y,rad));
    }
}
double solve(){
    int n1=0;
    p[++n1]=0;
    p[++n1]=2*PI;
    for(auto i:a) p[++n1]=i.X,p[++n1]=i.Y;
    sort(p+1,p+n1+1);
//    FOR(i,1,n1) cout<<p[i]<<" ";ENDL;
    for(auto i:a){
        int L=lower_bound(p+1,p+n1+1,i.X-eps)-p;
        int R=lower_bound(p+1,p+n1+1,i.Y-eps)-p;
//        cout<<L<<" "<<R<<'\n';
        h[L]++;h[R]--;
    }
    FOR(i,1,n1) h[i]+=h[i-1];
    double ans=0;
    REP(i,1,n1) if (h[i]) ans+=max(.0,p[i+1]-p[i]);
    return ans/(2*PI);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    printf("%.10f",solve());
}