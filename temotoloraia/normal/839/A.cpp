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
int n,k;
int S,s;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        x+=s;
        s=0;
        if (x>8){
            s=x-8;
            x=8;
        }
        S+=x;
        if (S>=k){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}