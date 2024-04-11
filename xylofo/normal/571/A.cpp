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

LL f(LL a){ return a*(a+1)/2;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    LL a,b,c,l,ans=0;
    cin>>a>>b>>c>>l;
    REP(i,l+1){
        ans+=f(i+1);
        ans-=f(max(0LL,i-max(0LL,(b+c-a+i+1)/2)+1));
        ans-=f(max(0LL,i-max(0LL,(c+a-b+i+1)/2)+1));
        ans-=f(max(0LL,i-max(0LL,(a+b-c+i+1)/2)+1));
    }
    cout<<ans<<endl;

	return 0;
}