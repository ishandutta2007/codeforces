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

int main(){
    int n;cin>>n;
    vector<int> x(n),y(n),z(n);
    vector<int> X,Y,Z;
    rep(i,n){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        X.push_back(x[i]);
        Y.push_back(y[i]);
        Z.push_back(z[i]);
    }
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    rep(i,n)x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin();
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    rep(i,n)y[i]=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin();
    sort(Z.begin(),Z.end());
    Z.erase(unique(Z.begin(),Z.end()),Z.end());
    rep(i,n)z[i]=lower_bound(Z.begin(),Z.end(),z[i])-Z.begin();

    vector<multiset<int>> v(n);
    map<int,set<pair<int,int>>> mp[n];
    rep(i,n){
        v[x[i]].insert(y[i]);
        mp[x[i]][y[i]].emplace(z[i],i);

    }
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int s,int t){
        return x[s]<x[t];
    });
    int x2=0;
    vector<int> used(n);
    vector<pair<int,int>> ans;
    for(auto i:ord){
        if(used[i])continue;
        auto itr=v[x[i]].lower_bound(y[i]);
        v[x[i]].erase(itr);
        mp[x[i]][y[i]].erase({z[i],i});
        while(v[x2].empty())++x2;
        itr=v[x2].lower_bound(y[i]);
        if(itr==v[x2].end())--itr;
        int y2=*itr;
        auto itr2=mp[x2][y2].lower_bound({z[i],-1});
        if(itr2==mp[x2][y2].end())--itr2;
        ans.emplace_back(i,itr2->second);
        used[itr2->second]=1;
        mp[x2][y2].erase(itr2);
        v[x2].erase(itr);
    }
    for(auto p:ans){
        cout<<p.first+1<<" "<<p.second+1<<endl;
    }
    return 0;
}