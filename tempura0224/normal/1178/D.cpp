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
    vector<int> isprime(101010,1);
    isprime[0]=isprime[1]=0;
    rep(i,100000){
        if(!isprime[i])continue;
        for(int j = 2*i ; j < 101010 ; j+=i){
            isprime[j]=0;
        }
    }
    vector<pair<int,int>> edge;
    vector<int> cnt(n);
    rep(i,n){
        edge.emplace_back(i,(i+1)%n);
        cnt[i]++;
        cnt[(i+1)%n]++;
    }
    int cur = 0;
    while(!isprime[edge.size()]){
        if(cnt[cur]==3){
            ++cur;continue;
        }
        cnt[cur]++;
        cnt[(cur+2)%n]++;
        edge.emplace_back(cur,(cur+2)%n);
        ++cur;
    }
    cout<<edge.size()<<endl;
    assert(edge.size()<=3*n/2);
    for(auto p : edge){
        printf("%d %d\n",p.first+1, p.second+1);
    }
    return 0;
}