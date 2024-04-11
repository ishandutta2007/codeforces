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
    int N,t;
    cin>>N>>t;
    t--;
    while(t>0){
        int a,b;
        cin>>a;
        t--;
        REP(i,a-1){
            cin>>b;
            t--;
        }
    }
    if(t==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}