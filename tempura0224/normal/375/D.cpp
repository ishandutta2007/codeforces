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
#include<numeric>

using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int beg[101010],en[101010];
vector<int> v[101010];

void dfs(int x,int p,int& idx){
    beg[x]=idx++;
    for(auto to:v[x]){
        if(to==p)continue;
        dfs(to,x,idx);
    }
    en[x]=idx;
}
int main(){
    int n,t;
    cin>>n>>t;
    int c[n];
    rep(i,n)scanf("%d",&c[i]);
    rep(i,n-1){
        int x,y;
        scanf("%d%d",&x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int idx=0;
    dfs(1,0,idx);
    int a[n];
    rep(i,n){
        a[beg[i+1]]=c[i];
    }
    const int b=512;
    int left[t],right[t],query[t];
    rep(i,t){
        int x,k;
        scanf("%d%d",&x,&k);
        query[i] = k;
        left[i] = beg[x];
        right[i] = en[x];
    }

    vector<int> ord(t);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        if(left[x]/b!=left[y]/b) return left[x]<left[y];
        return right[x] < right[y]; 
    });
    ll ret=0;
    int l=0,r=0;
    vector<int> cnt(101010);
    vector<int> sum(101010);
    int ans[t];
    for(auto i:ord){
        while(r<right[i]){
            ++cnt[a[r]];
            ++sum[cnt[a[r]]];
            ++r;
        }
        while(r>right[i]){
            --r;
            --sum[cnt[a[r]]];
            --cnt[a[r]];
        }
        while(l<left[i]){
            --sum[cnt[a[l]]];
            --cnt[a[l]];
            ++l;
        }
        while(l>left[i]){
            --l;
            ++cnt[a[l]];
            ++sum[cnt[a[l]]];
        }
        ans[i]=sum[query[i]];
    }
    rep(i,t){
        printf("%d\n",ans[i]);
    }
    return 0;
}