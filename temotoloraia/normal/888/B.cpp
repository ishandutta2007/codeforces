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
int n;
int main()
{
    cin>>n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++){
        char ch;
        cin>>ch;
        if (ch == 'U')
            x++;
        if (ch == 'D')
            x--;
        if (ch == 'L')
            y++;
        if (ch == 'R')
            y--;
    }
    cout<<n - abs (x) - abs (y)<<endl;
    return 0;
}