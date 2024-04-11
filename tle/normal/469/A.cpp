#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,p,s;
bool did[1001]={};
int main()
{
    cin>>n;
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>s;
        did[s]=1;
    }
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>s;
        did[s]=1;
    }
    bool ok=1;
    for(int i=1;i<=n;i++) ok&=did[i];
    if(ok) cout<<"I become the guy."; else cout<<"Oh, my keyboard!";
    //...
    return 0;
}