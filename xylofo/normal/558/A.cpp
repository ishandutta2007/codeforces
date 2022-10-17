#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
    int n,a,b;
    cin>>n;
    vector<PII> v1,v2;
    REP(i,n){
        cin>>a>>b;
        if(a<0)v1.PB(MP(-a,b));
        else v2.PB(MP(a,b));
    }
    sort(ALLOF(v1));
    sort(ALLOF(v2));
    int k=0;
    REP(i,min(v1.size(),v2.size()))k+=v1[i].Y+v2[i].Y;
    if(v1.size()>v2.size())k+=v1[v2.size()].Y;
    if(v2.size()>v1.size())k+=v2[v1.size()].Y;
    cout<<k<<endl;
    return 0;
}