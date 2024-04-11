#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005;
ll n,a,b,c,d;
int main() {
    cin>>n>>a>>c>>b>>d;
    if (n*a+2*b<n*c+d*2)
        cout<<"First"<<endl;
    else if (n*a+2*b==n*c+d*2)
        cout<<"Friendship\n";
    else
        cout<<"Second\n";
    return 0;
}