#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,aa,bb,cc,a,b,c;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a, aa^=a;
    for(int i=1;i<=n-1;i++) cin>>b, bb^=b;
    for(int i=1;i<=n-2;i++) cin>>c, cc^=c;
    cout<<(aa^bb)<<"\n"<<(bb^cc);
}