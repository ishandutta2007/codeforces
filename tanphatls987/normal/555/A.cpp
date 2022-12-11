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
const int N=2e5+10;

int n,m,m1,x;
ii pos[N];
vector <int> a[N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d",&m1);
        REP(j,0,m1){
            scanf("%d",&x);
            a[i].push_back(x);
            pos[x]=ii(i,j);
        }
    }
    int ans=0;
    FOR(i,1,n){
        int col=pos[i].X,re=pos[i].Y;
        int m1=a[col].size();
        if (i==1) while (re<m1-1&&a[col][re+1]==i+1) re++,i++;
        FORD(j,m1-1,re+1){
            ans++;
            int x=a[col].back();
            a[col].pop_back();
            a[++m].push_back(x);
            pos[x]=ii(m,0);
        }
        a[col].pop_back();
        ans++;
//        printf("%d %d\n",i,ans);
    }
    cout<<ans-1;
}