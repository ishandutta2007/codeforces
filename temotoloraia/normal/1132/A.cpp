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

const int N = 2100000;

int a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    if (a != d){
        cout << "0\n";
        return 0;
    }
    if (a == 0 && c > 0){
        cout << "0\n";
        return 0;
    }
    cout << "1\n";
    return 0;
}