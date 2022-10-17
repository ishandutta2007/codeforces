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
    set<ll> s;
    int n;
    cin>>n;
    for(ll k=(n&1);k*1234567<=n;k+=2){
        int m=n-k*1234567;
        for(ll k1=0;k1*123456<=m;k1++){
            int m1=m-k1*123456;
            if(m1%1234==0) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}