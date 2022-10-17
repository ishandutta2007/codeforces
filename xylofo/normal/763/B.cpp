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
    cout<<"YES"<<'\n';
    rep(i,0,n){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<1+2*((min(x1,x2)%2+2)%2)+(min(y1,y2)%2+2)%2<<'\n';
    }
    return 0;
}