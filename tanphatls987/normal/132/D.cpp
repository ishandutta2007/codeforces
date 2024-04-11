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
const int N=1e6+10;

string s;
int f[N][2],t[N][2];
bool minimize(int &x,int y){
    if (x>y) x=y;else return 0;
    return 1;
}
int main(){
    cin>>s;
    int n=s.length();
    FOR(i,0,1) f[0][i]=i;
    FOR(i,1,n){
        f[i][0]=f[i][1]=inf;
        if (s[i-1]=='1'){
            f[i][1]=f[i-1][1];
            t[i][1]=1;
            if (minimize(f[i][0],f[i-1][1]+1)) t[i][0]=1;
            if (minimize(f[i][0],f[i-1][0]+1)) t[i][0]=0;
        }else{
            if (minimize(f[i][1],f[i-1][1]+1)) t[i][1]=1;
            if (minimize(f[i][1],f[i-1][0]+1)) t[i][1]=0;
            f[i][0]=f[i-1][0];
            t[i][0]=0;
        }
    }
    printf("%d\n",f[n][0]);
    int cur=0;
    FORD(i,n,0){
        int ncur=t[i][cur];
        if (f[i][cur]!=f[i-1][ncur]) printf("%c2^%d\n",ncur?'-':'+',n-i);
        cur=ncur;
    }
}