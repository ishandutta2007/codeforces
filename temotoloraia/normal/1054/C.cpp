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
//#define temo

using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], b[N], c[N];

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++)
        cin>>b[i];
    for (int i = 1; i <= n; i++)
        c[i] = n - a[i] - b[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++)
            if (c[i] < c[j])
                a[i]--;
        for (int j = i + 1; j <= n; j++)
            if (c[i] < c[j])
                b[i]--;
        if (a[i] != 0 || b[i] != 0){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i = 1; i <= n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}