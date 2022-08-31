#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,m,a,b;
int main()
{
    cin>>n>>m>>a>>b;
    int black=n/m,minn=0x7ffffff;
    for(int i=0;i<=black+1;i++) minn=min(minn,i*b+max((n-i*m)*a,0));
    cout<<minn;
    return 0;
}