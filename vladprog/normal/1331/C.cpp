#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a;
    cin>>a;
    int b=0;
    #define get(i) ((a>>i)&1)
    #define set(i,x) b|=(x<<i)
    #define solve(i,j) set(j,get(i))
    solve(5,5);
    solve(4,0);
    solve(3,2);
    solve(2,3);
    solve(1,1);
    solve(0,4);
    cout<<b;
}