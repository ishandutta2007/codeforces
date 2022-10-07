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
const int N = 400005;
int n, m;
pair < int, int > P[N];
int b[N];
int a[N];
int Par (int x){
    if (a[x] == 1)
        return x;
    if (a[b[x]] == 1)
        return b[x];
    return b[x] = Par(b[x]);
}
main()
{
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>P[i].F;
        P[i].S = i;
    }
    sort (P + 1, P + n + 1);
    for (int i = 1; i <= n + 1; i++)
        b[i] = i - 1;
    for (int i = 0; i < n*2; i++){
        char ch = getchar();
        while (ch != '0' && ch != '1')
            ch = getchar();
        if (ch == '0'){
            m++;
            a[m]++;
            printf ("%d ",P[m].S);
            continue;
        }
        int t = Par(m);
        a[t]++;
        printf ("%d ",P[t].S);
    }
    return 0;
}