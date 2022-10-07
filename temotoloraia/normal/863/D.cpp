#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 200000;
int n, Q, m;
int a[MAXN + 5];
int t[MAXN + 5], l[MAXN + 5], r[MAXN + 5];
int main()
{
    scanf("%d %d %d", &n, &Q, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= Q; ++i)
        scanf("%d %d %d", &t[i], &l[i], &r[i]);
    while (m--){
        int I;
        cin>>I;
        for (int i = Q; i >= 1; --i){
            if (I < l[i] || r[i] < I)
                continue;
            if (t[i] == 1){
                I--;
                if (I < l[i])
                    I = r[i];
                continue;
            }
            I = r[i] + l[i] - I;
        }
        cout<<a[I]<<" ";
    }
    return 0;
}