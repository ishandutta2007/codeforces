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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    multiset<int> st[27];
    rep(i,n){
        if(t[i]=='?')st[26].insert(i+1);
        else st[t[i]-'a'].insert(i+1);
    }
    vector<pint> ans;
    vector<int> used(n);
    rep(i,n){
        int idx=s[i]-'a';
        if(s[i]=='?')continue;
        if(st[idx].size()){
            int ret=*st[idx].begin();
            ans.emplace_back(i+1,ret);
            st[idx].erase(ret);
            used[i]=1;
        }
    }
    rep(i,n){
        if(used[i])continue;
        int idx=26;
        if(s[i]=='?')continue;
        if(st[idx].size()){
            int ret=*st[idx].begin();
            ans.emplace_back(i+1,ret);
            st[idx].erase(ret);
            used[i]=1;
        }
    }
    rep(i,n){
        if(s[i]!='?')continue;
        rep(idx,27){
            if(st[idx].size()){
                int ret=*st[idx].begin();
                ans.emplace_back(i+1,ret);
                st[idx].erase(ret);
                used[i]=1;
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto p : ans){
        printf("%d %d\n",p.first,p.second);
    }
    return 0;
}