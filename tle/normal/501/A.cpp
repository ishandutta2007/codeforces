#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int score(int p,int t)
{
    return max(3*p/10,p-p/250*t);
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int sa=score(a,c),sb=score(b,d);
    if(sa>sb) cout<<"Misha"; 
    if(sa<sb) cout<<"Vasya";
    if(sa==sb) cout<<"Tie";
}