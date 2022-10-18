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

    int n;
    cin>>n;
    cout<<(n+1)+1+6*(n+1)<<"\n";
    for(int i=0;i<n+1;i++)
        cout<<2*i+1<<" "<<0<<"\n";
    int x=0,y=0;
    cout<<x<<" "<<y<<"\n";
    #define up cout<<x<<" "<<++y<<"\n"
    #define down cout<<x<<" "<<--y<<"\n"
    #define left cout<<--x<<" "<<y<<"\n"
    #define right cout<<++x<<" "<<y<<"\n"
    for(int i=0;i<n+1;i++)
        if(i%2==0)
            up,up,right,right,down,down;
        else
            down,down,right,right,up,up;
}