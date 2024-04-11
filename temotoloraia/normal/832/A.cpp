#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int main() {
    ll n,k;
    cin>>n>>k;
    n/=k;
    if (n%2==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}