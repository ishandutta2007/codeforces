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
    int n;
    cin>>n;
    int p[n];
    rep(i,n){
        scanf("%d",&p[i]);
        --p[i];
    }
    int pos[n];
    rep(i,n)pos[p[i]]=i;
    vector<pair<int, int>> ans;
    int m=n/2;
    rep(i,m){
        if(pos[m+i]<m){
            ans.emplace_back(pos[m+i],n-1);
            pos[p[n-1]]=pos[m+i];
            swap(p[pos[m+i]],p[n-1]);
            pos[m+i]=n-1;
        }
        if(pos[m+i]>=m){
            ans.emplace_back(pos[m+i],i);
            pos[p[i]]=pos[m+i];
            swap(p[pos[m+i]],p[i]);
            pos[m+i]=i;
            ans.emplace_back(pos[m+i],m+i);
            pos[p[m+i]]=pos[m+i];
            swap(p[pos[m+i]],p[m+i]);
            pos[m+i]=m+i;
        }
        if(pos[i]<m){
            ans.emplace_back(pos[i],n-1);
            pos[p[n-1]]=pos[i];
            swap(p[pos[i]],p[n-1]);
            pos[i]=n-1;
        }
        if(pos[i]>=m){
            ans.emplace_back(pos[i],i);
            pos[p[i]]=pos[i];
            swap(p[pos[i]],p[i]);
            pos[i]=i;
        }
    }
    cout<<ans.size()<<endl;
    for(auto p  : ans){
        printf("%d %d\n",p.first+1,p.second+1);
    }
    return 0;
}