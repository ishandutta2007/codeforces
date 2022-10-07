#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 100000;
int n, m;
int mas[100];
int main()
{
    cin>>n>>m;
    int x;
    cin>>x;
    mas[x]++;
    for (int i = 1; i < n; i++){
        int y;
        cin>>y;
        mas[y]++;
        if (y < x)
            x = y;
    }
    int a;
    cin>>a;
    mas[a]++;
    for (int i = 1; i < m; i++){
        int b;
        cin>>b;
        mas[b]++;
        if (b < a)
            a = b;
    }
    for (int i = 1; i < 10; i++)
        if (mas[i] > 1){
            cout<<i<<endl;
            return 0;
        }
    if (a > x)
        swap (a, x);
    cout<<a<<x<<endl;
    return 0;
}