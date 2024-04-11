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
    int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    int a=k,b=1;
    while (a<=r && b<=y){
        if (l<=a && x<=b){
            cout<<"YES"<<endl;
            return 0;
        }
        a+=k;
        b++;
    }
    cout<<"NO"<<endl;
    return 0;
}