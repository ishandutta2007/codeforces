#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7,BASE[2]={31,10007};
const int N=2e5+10;

int f[2][N][26],n;
ll h[2][2][N],pb[2][N];
string s1,s2;
bool can(int L1,int R1,int L2,int R2){
    FOR(i,0,25) if (f[0][R1][i]-f[0][L1-1][i]!=f[1][R2][i]-f[1][L2-1][i]) return 0;
    return 1;
}
ll call(int type1,int type2,int x,int y){
    return (h[type1][type2][y]-pb[type1][y-x+1]*h[type1][type2][x-1]%MOD+MOD)%MOD;
}
bool sequal(int L1,int R1,int L2,int R2){
    FOR(j,0,1) if (call(j,0,L1,R1)!=call(j,1,L2,R2)) return 0;
    return 1;
}
bool check(int L1,int R1,int L2,int R2){
    if (sequal(L1,R1,L2,R2)) return 1;
    if (((R1-L1+1)&1)||!can(L1,R1,L2,R2)) return 0;

    int len=(R1-L1+1)/2;
//    printf("%d %d %d %d %d\n",L1,R1,L2,R2,len);
    if (check(L1,L1+len-1,L2,L2+len-1)&&check(L1+len,R1,L2+len,R2)) return 1;
    if (check(L1,L1+len-1,L2+len,R2)&&check(L1+len,R1,L2,L2+len-1)) return 1;
    return 0;
}
void prepare(){
    n=s1.length();
    FOR(j,0,1){
        pb[j][0]=1;
        FOR(i,1,n) pb[j][i]=pb[j][i-1]*BASE[j]%MOD;
        FOR(i,1,n) h[j][0][i]=(h[j][0][i-1]*BASE[j]+s1[i-1]-'a')%MOD;
        FOR(i,1,n) h[j][1][i]=(h[j][1][i-1]*BASE[j]+s2[i-1]-'a')%MOD;
    }

    FOR(i,1,n){
        FOR(j,0,25) f[0][i][j]=f[0][i-1][j];
        f[0][i][s1[i-1]-'a']++;
    }
    FOR(i,1,n){
        FOR(j,0,25) f[1][i][j]=f[1][i-1][j];
        f[1][i][s2[i-1]-'a']++;
    }
}
int main(){
    cin>>s1>>s2;
    prepare();
    if (check(1,n,1,n)) printf("YES");
    else printf("NO");
}