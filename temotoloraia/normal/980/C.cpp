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
int a[100005];
int F[100005];
int B[100005];
int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 0; i < 2560; i++)
        F[i] = -1;
    for (int i = 1; i <= n; i++){
        if (F[a[i]] + 1){
            cout<<F[a[i]]<<" ";
            continue;
        }
        int p = a[i];
        for (int j = a[i] - 1; j >= a[i] - k + 1 && j >= 0; j--)
            if (F[j] + 1 > 0 && a[i] - j > B[j])
                break;
            else if (F[j] + 1 > 0){
                p = F[j];
                break;
            }
            else
                p = j;
        for (int j = p; j <= a[i]; j++)
            F[j] = p;
        B[a[i]] = k - (a[i] - p + 1);
        cout<<p<<" ";
    }
    cout<<endl;
    return 0;
}