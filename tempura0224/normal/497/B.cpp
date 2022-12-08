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


int next1[20][101010];
int next2[20][101010];

int get1(int s, int c){
    int i=0;
    while(c){
        if(c&1)s=next1[i][s];
        ++i;
        c>>=1;
    }
    return s;
}

int get2(int s, int c){
    int i=0;
    while(c){
        if(c&1)s=next2[i][s];
        ++i;
        c>>=1;
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    next1[0][n+1]=next2[0][n+1]=n+1;
    next1[0][n]=next2[0][n]=n+1;
    for(int i = n-1; i>=0; --i){
        if(a[i]==1){
            next1[0][i]=i+1;
            next2[0][i]=next2[0][i+1];
        }
        else {
            next2[0][i]=i+1;
            next1[0][i]=next1[0][i+1];
        }
    }
    rep(i,19){
        rep(j,n+2){
            next1[i+1][j]=next1[i][next1[i][j]];
            next2[i+1][j]=next2[i][next2[i][j]];
        }
    }
    vector<pair<int,int>> ans;
    REP(i,1,n+1){
        int cnt1=0, cnt2=0;
        int cur = 0;
        bool ok=true;
        int last=-1;
        while(1){
            if(cur==n)break;
            int t1=get1(cur,i), t2 = get2(cur,i);
            if(t1==n+1&&t2==n+1){
                ok=false;
                break;
            }
            if(t1<t2){
                ++cnt1;
                cur=t1;
                last=1;
            }
            else {
                ++cnt2;
                cur=t2;
                last=2;
            }
        }
        if(ok){
            if(cnt1>cnt2&&last==1)ans.emplace_back(cnt1,i);
            if(cnt2>cnt1&&last==2)ans.emplace_back(cnt2,i);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto p : ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}