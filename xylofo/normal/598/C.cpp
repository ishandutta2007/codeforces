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
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

typedef complex<ld> pt;
#define M_PI 3.14159265359

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<ld,int> > v(n);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        pt p(x,y);
        v[i]={arg(p),i};
    }
    sort(allof(v));
    int b=0;
    rep(i,0,n){
        ld x=v[(i+1)%n].X-v[i].X;
        while(x<0)x+=2*M_PI;
        ld y=v[(b+1)%n].X-v[b].X;
        while(y<0)x+=2*M_PI;
        if(x<y)b=i;
    }
    cout<<v[b].Y+1<<" "<<v[(b+1)%n].Y+1<<endl;
    return 0;
}