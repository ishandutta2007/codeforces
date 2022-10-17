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

bool f(const int& a,const int& b){return __builtin_popcount(a)<__builtin_popcount(b);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    VI v(N);
    int t=0;
    REP(i,N){
        cin>>v[i];
        t=max(v[i],t);
    }
    // sort(ALLOF(v),f);
    int b=INF;
    FOR(i,1,t+1){
        int k=0;
        for(int a:v){
            if(__builtin_popcount(i)>__builtin_popcount(a)){k=INF;break;}
            while(__builtin_popcount(i)<__builtin_popcount(a))a>>=1,k++;
            while(i<a)a>>=1,k++;
            while(a<i)a<<=1,k++;
            if(a!=i){k=INF;break;}
        }
        b=min(k,b);
    }
    cout<<b<<endl;
    return 0;
}