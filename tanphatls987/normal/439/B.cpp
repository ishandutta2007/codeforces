#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100001;


int n,x,a[maxi],i,j,c,sum;
int64_t tmp;
char s[18];
int add_num()
{
    j=16;c=0;
    while ((tmp>0)||(c>0))
    {
        //printf("%d %I64d %d\n",j,tmp,c);
        sum=s[j]-'0'+(tmp%10)+c;
        tmp/=10;
        c=sum/10;
        s[j]=sum%10+'0';
        j--;
        //printf("%d %I64d %d\n",j,tmp,c);
    }
}
int compar(const void* x,const void*y)
{
    return *(int*)x-*(int*)y;
}
int main()
{
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),compar);
    for(i=0;i<=16;i++) s[i]='0';
    s[17]='\0';
    for(i=0;i<n;i++)
    {
        tmp=int64_t(a[i])*int64_t(x);
        //printf("%d %I64d\n",i,tmp);
        add_num();
        //printf("tick\n");
        if (x>1) x--;
    }
    j=0;while (s[j]=='0') j++;
    for(i=j;i<17;i++)  printf("%c",s[i]);
}