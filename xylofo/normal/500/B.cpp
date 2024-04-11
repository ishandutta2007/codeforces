#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(it,st,en) for(int it=(st);it<(int)(en);++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define ALLOF(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef long long int LL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
const int INF=(int)1e9; 
const double EPS=(LD)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    VI v(N);
    REP(i,N)cin>>v[i];
    vector<string> s(N);
    REP(i,N)cin>>s[i];
    REP(k,N)REP(i,N)REP(j,N)if(s[i][k]=='1' && s[k][j]=='1')s[i][j]='1';
    REP(i,N){
        FOR(j,i,N){
            if(s[i][j]=='1' && v[j]<v[i])swap(v[i],v[j]);
        }
    }
    REP(i,N)cout<<v[i]<<" \n"[i==N-1];
    return 0;
}