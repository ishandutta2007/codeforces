#include<bits/stdc++.h>
using namespace std;
bool ok[3005];
int main()
{
    int m;
    cin>>m;
    int t;
    for(int i=1;i<=m;i++)
    {
        cin>>t;
        ok[t]=true;
    }
    for(int i=1;;i++)
    {
        if(ok[i]==false)
        {
            cout<<i;
            return 0;
        }
    }
}
///////asdiufhakjdhfkjxzf