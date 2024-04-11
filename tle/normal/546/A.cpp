#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long xx=0,k,n,w;
int main()
{
    cin>>k>>n>>w;
    for(int i=1;i<=w;i++) xx+=i*k;
    cout<<max(xx-n,0ll);
}