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

const int B  =2520;
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n){
        cin>>a[i];
        a[i]=(B+a[i]%B)%B;
    }
    int m[n];
    vector<int> v[n];
    rep(i,n){
        cin>>m[i];
        rep(j,m[i]){
            int x;
            cin>>x;
            --x;
            v[i].push_back(x);
        }
    }
    vector<vector<int>> ans(n,vector<int>(B,-1));
    vector<vector<int>> res(n,vector<int>(B,-1));
    vector<int> query;
    int idx = 0;
    rep(i,n)rep(j,B){
        if(ans[i][j]!=-1)continue;
        int cnt = 0;
        int ni = i, nj = j;
        while(ans[ni][nj]==-1){
            res[ni][nj]=cnt;
            ans[ni][nj]=idx;
            nj = (nj+a[ni])%B;
            ni = v[ni][nj%m[ni]];
            ++cnt;
        }
        if(ans[ni][nj]==idx){
            set<int> st;
            int t = cnt-res[ni][nj];
            rep(_,t){
                res[ni][nj]=-t;
                st.insert(ni);
                nj = (nj+a[ni])%B;
                ni = v[ni][nj%m[ni]];
            }
            query.push_back(st.size());
        }
        else {
            query.push_back(query[ans[ni][nj]]);
        }
        ++idx;
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        --x;
        y = (y%B+B)%B;
        cout<<query[ans[x][y]]<<"\n";
    }
    return 0;
}