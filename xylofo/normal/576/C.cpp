#pragma GCC optimize ("Ofast")
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

const int mn = 1000009;
int x[mn],y[mn],v[mn],yy[mn];

bool srt(const int& a, const int& b){
    if(yy[a]!= yy[b])return yy[a]< yy[b];
    if((yy[a])%2) return mp(x[a],y[a])<mp(x[b],y[b]);
    return mp(x[a],y[a])>mp(x[b],y[b]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d",&n);
    rep(i,0,n)scanf("%d%d",x+i,y+i),v[i]=i,yy[i]=y[i]/1000;
    sort(v,v+n,srt);
    rep(i,0,n) printf("%d ",v[i]+1);
    return 0;
}