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

int f(int a){
    if(a%4==0)return a;
    if(a%4==1)return 1;
    if(a%4==2)return a+1;
    if(a%4==3)return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vi v(n),l(m),r(m),b(m,-1),a(n);
    rep(i,0,n)cin>>v[i],a[i]=f(v[i]);
    rep(i,0,m)cin>>l[i]>>r[i],--l[i];
    vi acc(n,-1);
    rep(i,0,n){
        rep(j,i,n) 
            acc[j]=max(j!=i?acc[j-1]:0,a[i]^a[j]^(v[i]<v[j]?v[i]:v[j]));
        rep(j,0,m) if(i>=l[j] && i<r[j]) 
            b[j]=max(b[j],acc[r[j]-1]);
    }
    rep(i,0,m)
        cout<<b[i]<<"\n";
    return 0;
}