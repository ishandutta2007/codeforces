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
using namespace std;
const int MAXN = 1000000;
int n, A, B;
int a, b;
int main()
{
    cin>>n>>A>>B;
    for (a = 0; a * A <= n; a++){
        b = (n - a * A) / B;
        if (n == a * A + b * B)
            break;
    }
    if (n != a * A + b * B){
        cout<<-1;
        return 0;
    }
    for (int i = 1; i <= a * A; i++){
        if (i % A)
            cout<<i + 1<<" ";
        else
            cout<<i + 1 - A<<" ";
    }
    for (int i = 1; i <= b * B; i++){
        if (i % B)
            cout<<a * A + i + 1<<" ";
        else
            cout<<a * A + i + 1 - B<<" ";
    }
    cout<<endl;
    return 0;
}