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
    string s;
    cin>>s;
    int c=0;
    REP(i,N)c+=(s[i]=='0'?1:-1);
    cout<<abs(c)<<endl;
    return 0;
}