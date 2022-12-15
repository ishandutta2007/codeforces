#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

ll n, i, j, r, c;

int main(){
    cin >> n; c = 2;
    for(i=1;i<=n;i++){
        printf("%lld\n",(i*(i+1)*(i+1)-c));
        c = i;
    }
    return 0;
}