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
    int t = 0;
    rep(i,0,1005){
        if(t+i>n){
            cout<<i-1<<endl;
            rep(j,1,i-1){
                cout<<j<<" ";
                n-=j;
            }
            cout<<n<<endl;
            return 0;
        }
        t+=i;
    }
    return 0;
}