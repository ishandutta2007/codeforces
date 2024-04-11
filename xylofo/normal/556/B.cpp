#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#define FOR(i,a,b) for(auto i=(a);i<(b);++i)
#define REP(i,b) FOR(i,0,b)
#define ALLOF(v) v.begin(), v.end()

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long int LL;
typedef pair<int,int> PII;

int main(){
    int N;
    cin>>N;
    VI v(N);
    REP(i,N)cin>>v[i];
    REP(k,N){
        bool b=true;
        REP(i,N){
            if((v[i]+k*(i%2?1:-1) + N)%N != i)b=false;
        }
        if(b){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}