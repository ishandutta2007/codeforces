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
const int N = 1000000;
int g[N + 5], num[10][N + 5];
int main()
{
    for (int i = 1; i <= N; i++){
        if (i < 10){
            g[i] = i;
            continue;
        }
        int x = 1, y = i;
        while (y){
            if (y % 10)
                x *= (y % 10);
            y /= 10;
        }
        g[i] = g[x];
    }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j < 10; j++)
            num[j][i] = num[j][i - 1];
        num[g[i]][i]++;
    }
    int Q;
    cin>>Q;
    while (Q--){
        int l, r, k;
        cin>>l>>r>>k;
        cout<<num[k][r] - num[k][l - 1]<<endl;
    }
    return 0;
}