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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   int size(int x){
       return -par[find(x)];
   }
   bool same(int x,int y){
       return find(x)==find(y);
   }
};
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    rep(i,n)scanf("%d%d",&a[i],&b[i]);
    vector<int> v;
    rep(i,n){
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    rep(i,n){
        a[i]=lower_bound(v.begin(), v.end(), a[i])-v.begin();
        b[i]=lower_bound(v.begin(), v.end(), b[i])-v.begin();
    }
    int ok=v.size(),ng=-1;
    while(ok-ng>1){
        UnionFind uf(2*n);
        int mid=(ok+ng)/2;
        bool can1=true;
        rep(i,n){
            if(a[i]>mid){
                can1=false;
                break;
            }
            else if(b[i]>mid)continue;
            else uf.unite(a[i], b[i]);
        }
        if(!can1){
            ng=mid;
            continue;
        }
        vector<int> sz(2*n);
        bool can2=true;
        rep(i,n){
            if(++sz[uf.find(a[i])]>uf.size(a[i])){
                can2=false;
                break;
            }
        }
        if(!can2)ng=mid;
        else ok=mid;
    }
    if(ok==v.size())cout<<-1<<endl;
    else cout<<v[ok]<<endl;

    return 0;
}