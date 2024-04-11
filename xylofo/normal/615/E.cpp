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
    ll n;
    cin>>n;
    ll a=-1,b=1e9;
    while(a+1<b){
        ll mid=a+(b-a)/2;
        if(3*mid*(mid+1)>n-1)b=mid;
        else a=mid;
    }
    ll m=a+1;
    n=6*(m)-n+3*(m-1)*(m);
    ll x=2*m,y=0;
    ll dx[]={-1,-2,-1,+1,+2,+1};
    ll dy[]={-2, 0,+2,+2, 0,-2};
    rep(i,0,6){
        x+=min(m,n)*dx[i];
        y+=min(m,n)*dy[i];
        n-=min(m,n);
    }
    cout<<x<<" "<<y<<endl;

    return 0;
}