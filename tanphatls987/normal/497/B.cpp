#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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

int n,a[N],x,y;
vector <ii> s[2][N],ans;
ii p[N];
bool comp(ii a,ii b){
    if (a.X==b.X) return a.Y<b.Y;
    return a.X<b.X;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    if (a[n]==2) {
        FOR(i,1,n) if (a[i]==1) a[i]=2;
        else a[i]=1;
    }
    s[0][0].push_back(ii(0,0));
    s[1][0].push_back(ii(0,0));
    x=0,y=0;
    FOR(i,1,n){
        if (a[i]==1) x++;
        else y++;
        p[i]=ii(x,y);
        s[0][x].push_back(ii(y,i));
        s[1][y].push_back(ii(x,i));
    }
    //FOR(i,1,n) printf("%d %d\n",p[i].X,p[i].Y);
}
void DFS(int point,int x,int win,int loss){
    //printf("%d %d %d %d\n",point,x,win,loss);
    if (x==0){
        if (win>loss) ans.push_back(ii(win,point));
        return;
    }
    int cur;
    if (a[x]==1){
        cur=p[x].X-point;
        if (cur>=0) for(vector <ii>::reverse_iterator i=s[0][cur].rbegin();i<s[0][cur].rend();i++){
            if (p[x].Y-i->X>=point) break;
            DFS(point,i->Y,win+1,loss);
        }
    }else {
        cur=p[x].Y-point;
        if (cur>=0) for(vector <ii>::reverse_iterator i=s[1][cur].rbegin();i<s[1][cur].rend();i++){
            if (p[x].X-i->X>=point) break;
            DFS(point,i->Y,win,loss+1);
        }
    }
}
int main(){
    prepare();
    FOR(t,1,n) DFS(t,n,0,0);
    if (!ans.empty()) sort(ans.begin(),ans.end(),comp);
    printf("%d\n",ans.size());
    for(auto &i:ans) printf("%d %d\n",i.X,i.Y);
}