#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
LL n,k;
LL x=1,y=1;
int main() {
    cin>>n>>k;
    for (int i=0;i<k;i++){
        x*=2;
        y*=5;
    }
    while (n%x)
        n*=2;
    while (n%y)
        n*=5;
    cout<<n<<endl;
	return 0;
}