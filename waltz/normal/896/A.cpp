#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const char a[105]="What are you doing at the end of the world? Are you busy? Will you save us?";
const char b[105]="What are you doing while sending \"";
const char c[105]="\"? Are you busy? Will you send \"";
const char d[105]="\"?";
long long length[100005];
const long long inf=1234567890123456789ll;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    length[0]=strlen(a);
    int q;
    scanf("%d",&q);
    int i;
    int nn=strlen(b)+strlen(c)+strlen(d);
    int lena=strlen(a);
    int lenb=strlen(b);
    int lenc=strlen(c);
    int lend=strlen(d);
    for (i=1;i<=100000;i++)
    {
        length[i]=length[i-1]*2+nn;
        if (length[i]>=inf) length[i]=inf;
    }
    for (i=0;i<q;i++)
    {
        int x;
        long long y;
        cin>>x>>y;
        y--;
        if (y>=length[x])
        {
            printf(".");
            continue;
        }
        for (;;)
        {
            if (x==0)
            {
                printf("%c",a[y]);
                break;
            }
            if (y>=lenb)
            {
                y-=lenb;
            }
            else
            {
                printf("%c",b[y]);
                break;
            }
            if (y>=length[x-1])
            {
                y-=length[x-1];
            }
            else
            {
                x--;
                continue;
            }
            if (y>=lenc)
            {
                y-=lenc;
            }
            else
            {
                printf("%c",c[y]);
                break;
            }
            if (y>=length[x-1])
            {
                y-=length[x-1];
            }
            else
            {
                x--;
                continue;
            }
            if (y>=lend)
            {
                y-=lend;
            }
            else
            {
                printf("%c",d[y]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}