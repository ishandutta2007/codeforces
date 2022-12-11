#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main()
{
    cin>>a>>b>>c>>d>>e;
    int ans=min(a,b);
    ans=min(ans,min(min(c/2,d/7),e/4));
    cout << ans << endl;
    return 0;
}