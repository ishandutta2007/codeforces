#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,s[N];
ii a[N];
struct line{
    ll a,b,c;
    line (ll _a=0,ll _b=0,ll _c=0){
        a=_a;b=_b;c=_c;
    }
};
ll sqrlen(ii a){
    return 1LL*a.X*a.X+1LL*a.Y*a.Y;
}
ll operator %(ii a,ii b){
    return 1LL*a.X*b.Y-1LL*a.Y*b.X;
}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
struct point{
    double x,y;
};
line point_to_line(ii a,ii b){
    ii tmp=b-a;
    return line(-tmp.Y,tmp.X,-(1LL*a.X*-tmp.Y+1LL*tmp.X*a.Y));
}
point cross(line a,line b){
    point tmp;
    if (a.a==0||b.a==0) {
        if (a.a) return cross(b,a);
        tmp.y=(a.c+.0)/a.b;
    }else tmp.y=(b.c*a.a-a.c*b.a+.0)/(b.a*a.b-b.b*a.a);
    tmp.x=(-b.c-tmp.y*b.b+.0)/b.a;
    return tmp;
}

int CCW(ii a,ii b,ii c){
    ii tmp1=b-a,tmp2=c-a;
    ll ans=tmp1%tmp2;
    if (ans!=0) return ans/abs(ans);
    return (sqrlen(tmp1)<sqrlen(tmp2))?1:-1;
}
bool comp(ii a,ii b){
    return CCW(ii(0,0),b,a)==1;
}
void prepare(){
    scanf("%d%d%d",&n,&a[0].X,&a[0].Y);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+n+1,comp);
}
double solve(){
    double ans=inf;
    FOR(i,1,n) ans=min(ans,max((a[0].X+.0)/a[i].X,(a[0].Y+.0)/a[i].Y));
    int top=0;
    s[0]=n+1;
    FOR(i,1,n){
        while (top&&CCW(a[s[top-1]],a[s[top]],a[i])==1) top--;
        s[++top]=i;
    }
//    FOR(i,1,n) cout<<a[i].X<<" "<<a[i].Y<<'\n';
//    FOR(i,0,top) cout<<a[s[i]].X<<" "<<a[s[i]].Y<<'\n';
    line all=point_to_line(ii(0,0),a[0]);
    FOR(i,2,top) if (CCW(ii(0,0),a[0],a[s[i]])!=CCW(ii(0,0),a[0],a[s[i-1]])){
//        cout<<"->"<<s[i]<<" "<<s[i-1]<<'\n';
        line cur=point_to_line(a[s[i]],a[s[i-1]]);
        point tmp=cross(all,cur);
//        cout<<tmp.x<<" "<<tmp.y<<'\n';
        ans=min(ans,sqrt((sqrlen(a[0])+.0)/(tmp.x*tmp.x+tmp.y*tmp.y)));
    }
    return ans;
}
int main(){
    prepare();
    printf("%.12f",solve());
}