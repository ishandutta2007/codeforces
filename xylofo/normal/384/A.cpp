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
    int N;
    cin>>N;
    cout<<N*N/2 + (N%2==0 ? 0:1) <<endl;
    REP(i,N){
        REP(j,N){
            cout<<((i+j)%2==0? 'C':'.');
        }
        cout<<endl;
    }
    return 0;
}