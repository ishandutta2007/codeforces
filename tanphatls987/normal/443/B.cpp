#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define tick printf("tick\n")
using namespace std;

const int maxd=100000;
char s[210];
int n,k,i,j,st;
int main()
{
    scanf("%s\n",s);
    scanf("%d",&k);
    int m=strlen(s);
    n=m+k;
    for(i=n/2;i>=0;i--)
        for(st=0;st+2*i<=n;st++)
    {
        int ok=1;
        for(j=0;(j<i&&st+j+i<m);j++) if (s[st+j+i]!=s[st+j]) {ok=0;break;}
        if (ok) {cout<<2*i;return 0;}
    }
}