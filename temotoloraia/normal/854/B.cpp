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
const int N=100005;
int n,k;
int ans;
int main()
{
    cin>>n>>k;
    if (k==n || k==0)cout<<"0 0\n";
    else cout<<"1 "<<min(k*2,n-k)<<endl;
    return 0;
}