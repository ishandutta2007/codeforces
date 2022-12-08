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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> S(n);
    map<string, int> mp, id;
    rep(i,n){
        cin>>S[i];
        mp[S[i]] = 1;
        id[S[i]] = i;
    }
    vector<vector<int>> v(n);
    vector<int> cnt(n);

    rep(i,m){
        string t;
        cin>>t;
        int x;
        cin>>x;
        --x;
        vector<int> matches;
        rep(j,1<<k){
            string u = t;
            rep(l,k){
                if(j>>l&1)u[l]='_';
            }
            if(mp.count(u))matches.push_back(id[u]);
        }
        int m = matches.size();
        bool exi = false;
        for(auto e: matches){
            if(e==x)exi=true;
            else {
                v[x].push_back(e);
                cnt[e]++;
            }
        }
        if(!exi){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    queue<int> q;
    rep(i,n){
        if(!cnt[i])q.push(i);
    }
    vector<int> ans;
    while(q.size()){
        int x=q.front();q.pop();
        ans.push_back(x+1);
        for(auto to: v[x]){
            if(--cnt[to]==0)q.push(to);
        }
    }
    if(ans.size()<n){
        cout<<"NO"<<endl;
        return 0;
    } else {
        cout<<"YES"<<endl;
        for(auto e: ans)cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}