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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int ans=0;
    rep(i,1,int(sqrt(x)+1e-15)+1){
        if(i>n || x/i>n)continue;
        if(x%i==0 && i<=n && x/i<=n)ans+=2; 
        if(x==i*i)ans--;
    }
    cout<<ans<<endl;
    return 0;
}