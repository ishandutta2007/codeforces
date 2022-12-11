#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e2+10;

int h[N][10][2];
ii t[N][10][2];
string s;
void solve(){
    h[0][0][0]=1;
    int n=s.length();
    REP(i,0,n)
        REP(j,0,8) {
            if (h[i][j][0]){
                h[i+1][j][0]=1;
                h[i+1][(j*10+s[i]-'0')%8][1]=1;
                t[i+1][j][0]=t[i+1][(j*10+s[i]-'0')%8][1]=ii(0,j);
            }
            if (h[i][j][1]){
                h[i+1][j][1]=1;
                h[i+1][(j*10+s[i]-'0')%8][1]=1;
                t[i+1][j][1]=t[i+1][(j*10+s[i]-'0')%8][1]=ii(1,j);
            }
        }
    vector <int> ans;
    if (!h[n][0][1]){
        printf("NO");
        return;
    }
    int cur=1,x=0;
    FORD(i,n,1){
        ii next=t[i][x][cur];
        //printf("%d %d %d\n",i,x,next);
        if ((next.Y*10+s[i-1]-'0')%8==x) ans.push_back(s[i-1]-'0');
        cur=next.X;x=next.Y;
    }
    printf("YES\n");
    FORD(i,int(ans.size())-1,0) printf("%d",ans[i]);
}
int main(){
    cin>>s;
    solve();
}