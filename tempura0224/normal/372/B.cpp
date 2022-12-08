#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int sum[50][50][50];

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    string s[n];
    rep(i,n)cin>>s[i];
    vector<vector<int>> a(n+1,vector<int>(m+1));
    rep(i,n)rep(j,m)a[i+1][j+1]=(s[i][j]=='1');
    rep(i,n)rep(j,m+1)a[i+1][j]+=a[i][j];
    rep(i,n+1)rep(j,m)a[i][j+1]+=a[i][j];
    vector<int> x1(q),y1(q),x2(q), y2(q);
    rep(i,q){
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    vector<int> ord(q);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int p, int q){
        return y2[p]<y2[q];
    });
    int cur=1;
    vector<int> ans(q);
    for(auto i:ord){
        if(cur!=y2[i]+1){
            vector<vector<int>> nx(n,vector<int>(m));
            REP(j2,cur,y2[i]+1){
                rep(i2,n+1){
                    rep(j1,j2)rep(i1,i2){
                        if(a[i1][j1]+a[i2][j2]==a[i1][j2]+a[i2][j1]){
                            ++nx[i1][j1];
                        }
                    }
                    for(int j1=j2-2;j1>=0;--j1)for(int i1=i2-1;i1>=0;--i1){
                        nx[i1][j1]+=nx[i1][j1+1];
                    }
                    for(int j1=j2-1;j1>=0;--j1)for(int i1=i2-2;i1>=0;--i1){
                        nx[i1][j1]+=nx[i1+1][j1];
                    }
                    rep(i1,i2)rep(j1,j2){
                        sum[i1][j1][i2]+=nx[i1][j1];
                        nx[i1][j1]=0;
                    }
                }
            }
            cur=y2[i]+1;
        }
        REP(i2,x1[i],x2[i]+1)ans[i]+=sum[x1[i]-1][y1[i]-1][i2];
    }
    rep(i,q)printf("%d\n",ans[i]);
    return 0;
}