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
char a[4005],b[4005],c[4005];
long long powers[2005];
long long ans[4000005];
struct li_hash
{
    int x;
    li_hash * next;
};
li_hash * li[5000025];
li_hash * new_li_hash()
{
    static li_hash a[4000005];
    static int top=0;
    return &a[top++];
}
void insert_hash(int x,int y)
{
    li_hash * t=new_li_hash();
    t->next=li[x];
    t->x=y;
    li[x]=t;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%s%s%s",a,b,c);
    int sum=0;
    int i;
    powers[0]=1;
    for (i=1;i<=2000;i++)
    {
        powers[i]=powers[i-1]*131;
    }
    long long hash1=0,hash2=0,hash3=0;
    for (i=0;c[i]!='\0';i++)
    {
        hash3=hash3*131+c[i];
    }
    int lenc=strlen(c);
    for (i=0;a[i]!='\0';i++)
    {
        int j;
        hash1=0;
        hash2=0;
        for (j=0;b[j]!='\0';j++)
        {
            if (a[i+j]=='\0') break;
            if (b[j]!=a[i+j]) break;
            hash1=hash1*131+a[i+j];
            hash2=hash2*131+a[i+j];
            if (c[j]=='\0')
            {
                hash2-=a[i+j-lenc]*powers[lenc];
            }
        }
        if (b[j]=='\0')
        {
            for (;a[i+j]!='\0';j++)
            {
                if (hash2==hash3)
                {
                    //, 
                    ans[sum++]=hash1;
                }
                hash1=hash1*131+a[i+j];
                hash2=hash2*131+a[i+j];
                if (c[j]=='\0')
                {
                    hash2-=a[i+j-lenc]*powers[lenc];
                }
            }
            if (hash2==hash3)
            {
                //, 
                ans[sum++]=hash1;
            }
        }
    }
    int tot_ans=0;
    for (i=0;i<sum;i++)
    {
        int x=ans[i]%5000011;
        if (x<0) x=-x;
        li_hash * t=li[x];
        int temp=ans[i]%1000000009;
        for (;t!=0;t=t->next)
        {
            if (t->x==temp) break;
        }
        if (t==0)
        {
            insert_hash(x,temp);
            tot_ans++;
        }
    }
    printf("%d\n",tot_ans);
    //fprintf(stderr,"%d\n",clock());
    return 0;
}