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
const int N = 100005;
int n;
int a[N], b[N];
int x, y;
int i1, i2;
int main() {
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        if (y < a[i] && a[i] < x)
            b[i1]++;
        if (a[i] > y){
            y = a[i];
            i2 = i;
        }
        if (y > x){
            b[i]--;
            swap (x, y);
            swap (i1, i2);
        }
    }
    x = -1000, y = 0;
    for (int i = 1; i <= n; i++)
    if (b[i] > x || (b[i] == x && a[i] < y)){
        x = b[i];
        y = a[i];
    }
    cout<<y<<endl;
    return 0;
}