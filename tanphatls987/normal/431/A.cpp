#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <string.h>

using namespace std;

const int maxi=100000;

string a;
int n,i,s[5]={0},h[5]={0},ans=0;

int main()
{
    for(i=1;i<5;i++) scanf("%d",&s[i]);
    cin>>a;
    for(i=0;i<a.length();i++) h[(a[i])-'0']++;
    ans=s[1]*h[1]+s[2]*h[2]+s[3]*h[3]+s[4]*h[4];
    printf("%ld",ans);
}