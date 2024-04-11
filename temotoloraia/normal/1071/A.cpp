#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const int N = 2e5 + 5;

ll a, b;
bool check (ll x){
    ll A = a, B = b;
    for (ll i = x; i >= 1; i--){
        if (A >= i){
            A -= i;
            continue;
        }
        if (B < i)
            return 0;
        B -= i;
    }
    return 1;
}
vector < int > v1, v2;

int main()
{
    cin>>a>>b;
    ll I = 0;
    for (ll i = 18; i >= 0; i--){
        if (check (I + (1<<i)))
            I += (1<<i);
    }
    for (int i = I; i >= 1; i--){
        if (a >= i){
            a -= i;
            v1.pb (i);
        }
        else {
            b -= i;
            v2.pb (i);
        }
    }
    cout<<v1.size()<<endl;
    for (int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    cout<<v2.size()<<endl;
    for (int i = 0; i < v2.size(); i++)
        cout<<v2[i]<<" ";
    cout<<endl;
    return 0;
}