/*
By: zzq
PE
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <stack>
using namespace std;
int n;
string str;
double inc[600001],ssum[600001];
bool isvowel(char s)
{
	return s=='I'||s=='E'||s=='A'||s=='O'||s=='U'||s=='Y';
}
int main()
{
    cin>>str;
    n=str.length();
    for(int i=1;i<=n;i++) ssum[i]=ssum[i-1]+1.0/i;
    inc[1]=ssum[n];
    for(int i=2;i<=n;i++)
    {
        inc[i]=inc[i-1]+(ssum[n+1-i]-ssum[i-1]); //i~n+1-i
    }
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        if(isvowel(str[i-1]))
        {
            ans+=inc[min(i,n+1-i)];
        }
    }
    printf("%.7lf",ans);
    return 0;
}