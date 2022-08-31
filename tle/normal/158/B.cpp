#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,s[1000001],rp[100000];
int getint()
{
    int tmp=0; bool fu=0; char s;
    while(s=getchar(),s!='-'&&(s<'0'||s>'9')) ;
    if(s=='-') fu=1; else tmp=s-'0';
    while(s=getchar(),s>='0'&&s<='9') tmp=tmp*10+s-'0';
    if(fu) return -tmp; else return tmp;
}
#define IO =getint()
int main()
{
    int nn=0;
    n IO;
    for(int i=1;i<=n;i++) s[i] IO, rp[s[i]]++;
    int ans=rp[4],s1=rp[1],s2=rp[2],s3=rp[3];
    if(s3<=s1)
    {
        s1-=s3; ans+=s3; s3=0;
    }
    else
    {
        s1=0; ans+=s3; s3=0;
    }
    ans+=s2/2; s2%=2;
    if(s2==1&&s1>=2)
    {
        s1-=2; s2--; ans++;
    }
    else if(s2==1)
    {
        s1=0; s2--; ans++;
    }
    ans+=s1/4; s1%=4;
    if(s1) ans++;
    cout<<ans;
}