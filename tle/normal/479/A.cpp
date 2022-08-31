//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int w[]={a+b+c,a+b*c,a*b+c,a*b*c,(a+b)*c,a*(b+c)};
    int maxn=-100;
    for(int i=0;i<=5;i++) maxn=max(maxn,w[i]);
    cout<<maxn;
    return 0;
}