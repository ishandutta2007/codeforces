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
    int n; cin>>n;
    map<int,int> a,f,l;
    REP(i,n){
        int t;
        cin>>t;
        if(!a[t])f[t]=i;
        a[t]++;
        l[t]=i;
    }
    int b=a.begin()->X;
    for(auto t:a){
        if(t.Y>a[b])b=t.X;
        else if(t.Y == a[b] && l[t.X]-f[t.X]<l[b]-f[b])b=t.X;
    }
    cout<<f[b]+1<<" "<<l[b]+1<<endl;
    return 0;
}