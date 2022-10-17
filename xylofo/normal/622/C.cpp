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
    int n,m;
    cin>>n>>m;
    int l=-1,x,r;
    vi v(n+1,-1),a(n+1,0);
    rep(i,1,n+1){
        cin>>x;
        a[i]=x;
        if(x==l)v[i]=v[i-1];
        else v[i]=i-1;
        l=x;
    }
    rep(i,0,m){
        cin>>l>>r>>x;
        if(a[r]!=x)cout<<r;
        else if(v[r]>=l)cout<<v[r];
        else cout<<-1;
        cout<<'\n';
    }
    return 0;
}