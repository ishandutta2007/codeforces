#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("359.inp","r",stdin)
#define OUTPUT freopen("359.out","w",stdout)
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
const int N=3e5+10;

int n,a[N],b[2][N][20];
int get(int type,int l,int r){
    int bar=log2(r-l+1);
    if (type==0) return __gcd(b[0][l][bar],b[0][r-(1<<bar)+1][bar]);
    return min(b[1][l][bar],b[1][r-(1<<bar)+1][bar]);
}
bool check(int M){
    FOR(i,1,n-M) if (get(0,i,i+M)==get(1,i,i+M)) return 1;
    return 0;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) b[0][i][0]=b[1][i][0]=a[i];
    FOR(lv,1,19)
        FOR(i,1,n-(1<<lv)+1){
            int sel=i+(1<<(lv-1));
            b[0][i][lv]=__gcd(b[0][i][lv-1],b[0][sel][lv-1]);
            b[1][i][lv]=min(b[1][i][lv-1],b[1][sel][lv-1]);
        }
}
int main(){
    prepare();
    int L=0,R=n-1;
    while (L<=R){
        int M=(L+R)/2;
        if (check(M)) L=M+1;
        else R=M-1;
    }
//    cout<<get(0,2,5)<<" "<<get(1,1,4)<<'\n';
    vector <int> ans;
    FOR(i,1,n-R) if (get(0,i,i+R)==get(1,i,i+R)) ans.push_back(i);
    printf("%d %d\n",ans.size(),R);
    for(auto i:ans) printf("%d ",i);
}