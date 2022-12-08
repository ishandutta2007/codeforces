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

void solve(string& s, int l, int r, int k, vector<pair<int,int>>& ans){
    if(k==0)return;
    if(s[r-1]=='('){
        int j = r-1;
        while(s[j]=='(')--j;
        ans.emplace_back(j+1,r);
        reverse(s.begin()+j,s.begin()+r);
    }
    if(k==1){
        if(l>=1)return;
        if(s[0]==')'){
            int j = 0;
            while(s[j]==')')++j;
            ans.emplace_back(1,j+1);
            reverse(s.begin(),s.begin()+j+1);
        }
        solve(s,1,r-1,(r-2)/2,ans);
        return;
    }
    if(s[r-2]==')'){
        int j = r-2;
        while(s[j]==')')--j;
        ans.emplace_back(j+1,r-1);
        reverse(s.begin()+j,s.begin()+r-1);
    }
    solve(s,l,r-2,k-1,ans);
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<pair<int,int>> ans;
    solve(s,0,n,k,ans);
    cout<<ans.size()<<endl;
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
}

int main(){
    int t;cin>>t;
    rep(i,t)solve();
    
    return 0;
}