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
LL N,n,m,ans=1e9;
int main() {
    cin>>N;
    for (n=1;n<=N;n++){
        m=(N-1)/n;
        ans=min(ans,2*(n+m+1));
    }
    cout<<ans<<endl;
	return 0;
}