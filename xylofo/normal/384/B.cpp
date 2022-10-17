#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(it,st,en) for(int it=st;it<en;++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=c.begin();it!=c.end();it++)
#define ALLOF(c) c.begin(), c.end()
#define LL long long int
#define PB push_back
#define MP make_pair
#define INF INT_MAX
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> PII;

int main(){
    int M,N;
    bool K;
    cin>>N>>M>>K;
    VII arrs(N,VI(M));
    REP(i,N){
        REP(j,M){
            cin>>arrs[i][j];
        }
    }
    cout<<M*(M-1)/2<<endl;
    REP(i,M){
        FOR(j,i+1,M){
            if(!K)cout<<i+1<<' '<<j+1<<endl;
            else cout<<j+1<<' '<<i+1<<endl;
        }
    }
    return 0;
}