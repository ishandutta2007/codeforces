#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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

int m,h1,a1,x1,y1,h2,a2,x2,y2,h[N];
ii meet(int x,int a,int b,int tar){
    ii ans=ii(0,0);
    memset(h,0,sizeof(h));
    while (1){
        //printf("%d %d\n",ans.X,x);
        if (h[x]) return ii(-1,-1);
        h[x]=1;
        if (x==tar) break;
        x=(1LL*a*x+b)%m;
        ans.X++;
    }
    do{
        if (ans.Y>m) {
            ans.Y=-1;
            break;
        }
        ans.Y++;
        x=(1LL*x*a+b)%m;
    }while (x!=tar);
    return ans;
}
ll solve(){
    ii ans1=meet(h1,x1,y1,a1),ans2=meet(h2,x2,y2,a2);
    //printf("%d %d %d %d\n",ans1.X,ans1.Y,ans2.X,ans2.Y);
    if (ans1.X==-1||ans2.X==-1) return -1;
    if (ans1.Y==-1&&ans2.Y==-1) return (ans1.X==ans2.X)?ans1.X:-1;
    if (ans2.Y==-1){
        if ((ans2.X-ans1.X)%ans1.Y) return -1;
        return (ans2.X>=ans1.X)?ans2.X:-1;
    }
    if (ans1.Y==-1){
        if ((ans1.X-ans2.X)%ans2.Y) return -1;
        return (ans1.X>=ans2.X)?ans1.X:-1;
    }
    FOR(ans,0,ans1.Y) if ((1LL*ans2.Y*ans+ans2.X-ans1.X)%ans1.Y==0){
        ll bar=(1LL*ans2.Y*ans+ans2.X-ans1.X)/ans1.Y;
        if (bar>=0) return 1LL*ans*ans2.Y+ans2.X;
    }
    return -1;
}
int main(){
    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
    cout<<solve();
}