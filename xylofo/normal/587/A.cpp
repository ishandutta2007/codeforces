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
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int w[1100006];

int main(){
    memset(w,0,sizeof(w));
    int n,a;
    scanf("%d",&n);
    rep(i,0,n){
       scanf("%d",&a);
       w[a]++;
    }
    int ans=0;
    rep(i,0,1100005){
        if(w[i]%2==1)ans++;
        w[i+1]+=w[i]/2;
    }
    printf("%d\n",ans);
    return 0;
}