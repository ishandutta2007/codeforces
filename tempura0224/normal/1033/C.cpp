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

bool ok[101010];
int cnt[101010];
int main(){
    int n;cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    vector<int> v[n];
    rep(i,n){
        int x=i%a[i];
        for(int j=x;j<n;j+=a[i]){
            if(a[j]>a[i])v[j].push_back(i),++cnt[i];
        }
    }
    queue<int> q;
    rep(i,n){
        if(!cnt[i])q.push(i);
    }
    while(q.size()){
        int p=q.front();q.pop();
        for(auto to:v[p]){
            ok[to]|=(!ok[p]);
            if(--cnt[to]==0)q.push(to);
        }
    }
    rep(i,n)cout<<(char)('B'-ok[i]);
    cout<<endl;
    return 0;
}