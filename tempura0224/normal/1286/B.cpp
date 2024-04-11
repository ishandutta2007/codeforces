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

vector<int> v[2020];
int ans[2020],a[2020];

vector<pair<int,int>> dfs(int x,int& st){
    vector<pair<int,int>> ret = {};
    for(auto to:v[x]){
        auto e  = dfs(to,st);
        ret.insert(ret.end(),e.begin(),e.end());
    }
    if(a[x]>ret.size()){
        cout<<"NO"<<endl;
        exit(0);
    }
    vector<pair<int,int>> nr(1+ret.size());
    rep(i,ret.size()){
        if(i<a[x])nr[i]=ret[i];
        else if(i==a[x]){
            nr[i]={ret[i].first,x};
            ans[x]=ret[i].first;
            REP(j,i,ret.size()){
                ans[ret[j].second]++;
                nr[j+1]={ans[ret[j].second],ret[j].second};
            }
            break;
        }
    }
    if(a[x]==ret.size()){
        int s= nr.size();
        nr[s-1]={st,x};
        ans[x]=st;
    }
    st += 1;
    return nr;
}

int main(){
    int n;
    cin>>n;
    int p=-1;
    rep(i,n){
        int x;cin>>x;
        if(x){
            v[--x].push_back(i);
        }
        else p=i;
        cin>>a[i];
    }
    int st = 1;
    dfs(p,st);
    cout<<"YES"<<endl;
    rep(i,n)cout<<ans[i]<<endl;
    return 0;
}