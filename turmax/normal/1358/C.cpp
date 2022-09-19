#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int a=(x2-x1);int b=(y2-y1);
    if(a>=b)
    {
        swap(a,b);
    }
    cout<<a*(a-1)+(b-a+1)*a+1<<endl;
    }
    return 0;
}