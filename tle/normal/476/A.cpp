//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
bool appeared[100001]={};
int main()
{
    int n,m,s1,s2;
    cin>>n>>m;
    s2=n/2; s1=n%2;
    while((s1+s2)%m!=0&&s2!=0&&!appeared[(s1+s2)%m])
    {
        appeared[(s1+s2)%m]=1;
        s1+=2;
        s2--;
    }
    if((s1+s2)%m==0) cout<<s1+s2; else cout<<-1;
    return 0;
}