#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;
int n,c,next,last,i,ans;
int main()
{
    cin>>n>>c;
    cin>>last;
    ans=0;
    for(i=1;i<n;i++)
    {
        cin>>next;
        if (last-next>ans) ans=last-next;
        last=next;
    }
    if (ans-c>0) cout<<ans-c;else cout<<0;
}