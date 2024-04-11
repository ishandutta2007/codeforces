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
int n, k;
char a[10][1000];
int main()
{
    cin>>n>>k;
    cout<<"YES\n";
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = '.';
    if (k%2 == 0){
        for (int i = 2; 2 * (i - 1) <= k; i++)
            a[2][i] = '#', a[3][i] = '#';
    }
    else {
        a[2][(n+1)/2] = '#';
        k--;
        for (int i = 2; i < n - i + 1 && k; i++){
            k -= 2;
            a[2][i] = '#';
            a[2][n - i + 1] = '#';
        }
        for (int i = 2; i < n - i + 1 && k; i++){
            k -= 2;
            a[3][i] = '#';
            a[3][n - i + 1] = '#';
        }
    }
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= n; j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}