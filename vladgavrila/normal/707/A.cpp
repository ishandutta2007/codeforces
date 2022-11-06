#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
string s;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            cin>>s;
            if(s[0]=='C' || s[0]=='M' || s[0]=='Y')
            {
                cout<<"#Color\n";
                return 0;
            }
        }

    cout<<"#Black&White\n";
    return 0;
}