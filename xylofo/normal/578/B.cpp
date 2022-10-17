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
typedef vector<ll> vi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    ll x=1,xx;
    cin>>n>>k>>xx;
    rep(i,0,k)x*=xx;
    vi v(n),v1(n),v2(n);
    rep(i,0,n)cin>>v[i];
    rep(i,0,n)v1[i]=v[i] | (i?v1[i-1]:0);
    rep(i,0,n)v2[n-1-i]=v[n-1-i] | (i?v2[n-i]:0);
    ll m=0;
    rep(i,0,n){
        m=max(m,(i?v1[i-1]:0) | (v[i]*x) | (i==n-1?0:v2[i+1]));
    }
    cout<<m<<endl;

    return 0;
}