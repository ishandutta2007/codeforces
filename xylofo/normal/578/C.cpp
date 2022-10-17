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
const double EPS=(double)1e-9;

double minimize(double x, vi& v){
    double acc=0;
    double ans=0;
    rep(i,0,v.size()){
        acc+=v[i]-x;
        ans=min(ans,acc);
        acc=min((double)0.0,acc);
    }
    return -ans;
}
double maximize(double x, vi& v){
    double acc=0;
    double ans=0;
    rep(i,0,v.size()){
        acc+=v[i]-x;
        ans=max(ans,acc);
        acc=max((double)0.0,acc);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    double a=-10000, b=10000;
    rep(i,0,100){
        double x=(a+b)/2.0;
        if(maximize(x,v)>minimize(x,v))a=x;
        else b=x;
    }
    printf("%.19lf\n",(minimize((a+b)/2,v)+maximize((a+b)/2,v))/2.0);
    return 0;
}