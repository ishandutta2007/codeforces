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
int main() {
    int R,D;
    cin>>R>>D;
    int n;
    cin>>n;
    int ans=0;
    while (n--){
        int x,y,r;
        cin>>x>>y>>r;
        if (x*x+y*y<=(R-r)*(R-r) && x*x+y*y>=(R-D+r)*(R-D+r))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}