#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int t=0;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if(t<a)
            break;
        t=max(t,b);
    }
    if(t>=m)
        cout<<"YES";
    else
        cout<<"NO";
}