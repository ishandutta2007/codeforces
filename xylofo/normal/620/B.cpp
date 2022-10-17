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

int seg[]={6,2,5,5,4,5,6,3,7,6};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    ll ans=0;
    cin>>a>>b;
    rep(i,a,b+1){
        int x=i;
        while(x){
            ans+=seg[x%10];
            x/=10;
        }
    }
    cout<<ans<<endl;
    return 0;
}