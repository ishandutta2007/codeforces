#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7,BASE=37;
const int N=5e3+10;

int n,f[N][N];
ll ha[N],pb[N];
string s;
ll calhash(int pos,int len){
    int R=pos+len-1;
    return (ha[R]-ha[pos-1]*pb[len]%MOD+MOD)%MOD;
}
bool larger(int x,int y,int len){
    int L=0,R=len-1;
    while (L<=R){
        int mid=(L+R)/2;
        if (calhash(x,mid+1)==calhash(y,mid+1)) L=mid+1;
        else R=mid-1;
    }
//    cout<<"->"<<L<<'\n';
    if (L==len) return 0;
    return s[x+L-1]>s[y+L-1];
}
void prepare(){
    cin>>n>>s;
    pb[0]=1;
    FOR(i,1,n) {
        ha[i]=(ha[i-1]*BASE+s[i-1]-'0')%MOD;
        pb[i]=pb[i-1]*BASE%MOD;
    }
    /*int test,xa,ya,len;
    cin>>test;
    while (test--){
        cin>>xa>>ya>>len;
        cout<<larger(xa,ya,len)<<'\n';
    }*/
}
int solve(){
    f[0][0]=1;
    FOR(i,0,n)
        FOR(j,1,n){
            f[i][j]=f[i][j-1];
            if (j<=i&&s[i-j]!='0'){
                if (i-j>=j&&larger(i-j+1,i-2*j+1,j)) f[i][j]=(f[i][j]+f[i-j][j])%MOD;
                else f[i][j]=(f[i][j]+f[i-j][j-1])%MOD;
            }
//            cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
        }
    return f[n][n];
}
int main(){
    prepare();
    cout<<solve();
}