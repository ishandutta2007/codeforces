#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y,k,n;
    cin >> y >> k >> n;
    bool f=0;
    for(int i=k; i<=n; i+=k)
    {
        if(i-y>0)
        {
            cout << i-y << " ";
            f=1;
        }
    }
    if(f==0) cout << "-1\n";
 
}