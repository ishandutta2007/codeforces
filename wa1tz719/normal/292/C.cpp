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
int a[15];
int num[15];
int n;
int length=0;
int ip[10005][5];
int now_ip[5];
int sum=0;
void find_dots(int place,int now)
{
    if ((now==length)&&(place==4))
    {
        int i;
        for (i=0;i<4;i++)
        {
            ip[sum][i]=now_ip[i];
        }
        sum++;
        return;
    }
    if (now==length) return;
    if (place==4) return;
    if (num[now]==0)
    {
        now_ip[place]=0;
        find_dots(place+1,now+1); 
        return;
    }
    now_ip[place]=0;
    for (;;)
    {
        now_ip[place]=now_ip[place]*10+num[now];
        if (now_ip[place]>=256) return;
        find_dots(place+1,now+1);
        now++;
    }
}
void make(int l,int r,int digit)
{
    if (l<=r)
    {
        int i;
        for (i=0;i<n;i++)
        {
            num[l]=a[i];
            num[r]=a[i];
            make(l+1,r-1,digit|(1<<i));
        } 
    }
    else if (digit==(1<<n)-1)
    {
        find_dots(0,0);
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    if (n>=7)
    {
        puts("0");
        return 0;
    }
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=4;i<=12;i++)
    {
        length=i;
        make(0,i-1,0);
    }
    printf("%d\n",sum); 
    for (i=0;i<sum;i++)
    {
        printf("%d.%d.%d.%d\n",ip[i][0],ip[i][1],ip[i][2],ip[i][3]);
    }
    return 0;
}