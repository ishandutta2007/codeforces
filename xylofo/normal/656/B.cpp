#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi x(n),y(n);
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)cin>>y[i];
    int cnt=0;
    rep(k,0,720720){
        rep(i,0,n) if(k%x[i] == y[i]){cnt++; goto con;}
        con:
        ;
    }
    cout<<setprecision(100);
    cout<<double(cnt)/720720<<endl;
    return 0;
}