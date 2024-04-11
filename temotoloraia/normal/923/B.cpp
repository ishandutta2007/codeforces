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
ll a[N], b[N];
ll S;
priority_queue < ll > Q;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++)
        cin>>b[i];
    for (int i = 1; i <= n; i++){
        a[i] += S;
        S += b[i];
        Q.push (-a[i]);
        ll x = 0;
        while (Q.size() > 0){
            if (-Q.top() <= S){
            x += -Q.top() - S + b[i];
            Q.pop();}
            else
                break;
        }
        x += b[i] * Q.size();
        cout<<x<<" ";
    }
    return 0;
}