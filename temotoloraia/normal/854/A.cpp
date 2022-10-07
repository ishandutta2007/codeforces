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
int main()
{
    int n;
    cin>>n;
    int A,B;
    double ans=0;
    for (int a=1;a<=n;a++){
        int b=n-a;
        if (a<b && __gcd(a,b)==1){
            double x=a,y=b;
            x/=y;
            if (x>ans){
                ans=x;
                A=a;
                B=b;
            }
        }
    }
    cout<<A<<" "<<B<<endl;
    return 0;
}