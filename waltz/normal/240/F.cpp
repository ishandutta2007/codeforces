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
bool tag[26][1<<18];
int val[26][1<<18];
char a[100005];
void bulid_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        int i;
        for (i=0;i<26;i++)
        {
            val[i][num]=0;
            tag[i][num]=0;
        }
        val[a[l]-'a'][num]=1;
        return;
    }
    int mid=(l+r)/2;
    bulid_tree(num*2+1,l,mid);
    bulid_tree(num*2+2,mid,r);
    int i;
    for (i=0;i<26;i++)
    {
        val[i][num]=val[i][num*2+1]+val[i][num*2+2];
    }
}
void push_down(int num,int l,int r,int x)
{
    if (!tag[x][num]) return;
    int mid=(l+r)/2;
    tag[x][num]=0;
    if (val[x][num]==0)
    {
        val[x][num*2+1]=0;
        val[x][num*2+2]=0;
    }
    else
    {
        val[x][num*2+1]=mid-l;
        val[x][num*2+2]=r-mid;
    }
    tag[x][num*2+1]=true;
    tag[x][num*2+2]=true;
}
int query(int num,int l,int r,int l0,int r0,int x)
{
    if ((l0<=l)&&(r<=r0))
    {
        return val[x][num];
    }
    push_down(num,l,r,x);
    int mid=(l+r)/2;
    int sum=0;
    if (l0<mid) sum+=query(num*2+1,l,mid,l0,r0,x);
    if (mid<r0) sum+=query(num*2+2,mid,r,l0,r0,x);
    return sum;
}
void clear(int num,int l,int r,int l0,int r0,int x)
{
    if ((l0<=l)&&(r<=r0))
    {
        val[x][num]=0;
        tag[x][num]=true;
        return;
    }
    push_down(num,l,r,x);
    int mid=(l+r)/2;
    if (l0<mid) clear(num*2+1,l,mid,l0,r0,x);
    if (mid<r0) clear(num*2+2,mid,r,l0,r0,x);
    val[x][num]=val[x][num*2+1]+val[x][num*2+2];
}
void change(int num,int l,int r,int l0,int r0,int x)
{
    if ((l0<=l)&&(r<=r0))
    {
        val[x][num]=r-l;
        tag[x][num]=true;
        return;
    }
    push_down(num,l,r,x);
    int mid=(l+r)/2;
    if (l0<mid) change(num*2+1,l,mid,l0,r0,x);
    if (mid<r0) change(num*2+2,mid,r,l0,r0,x);
    val[x][num]=val[x][num*2+1]+val[x][num*2+2];
}
int num[35];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    int i;
    bulid_tree(0,0,n);
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        int j;
        int the_odd=-1;
        for (j=0;j<26;j++)
        {
            num[j]=query(0,0,n,x,y,j);
            if (num[j]&1)
            {
                if (the_odd!=-1) break;
                the_odd=j;
            }
        }
        if (j<26) continue;
        int now=0;
        for (j=0;j<26;j++)
        {
            clear(0,0,n,x,y,j);
            if (num[j]<2) continue;
            change(0,0,n,x+now,x+now+num[j]/2,j);
            change(0,0,n,y-now-num[j]/2,y-now,j);
            now+=num[j]/2;
        }
        if (the_odd!=-1)
        {
            change(0,0,n,x+now,x+now+1,the_odd);
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<26;j++)
        {
            if (query(0,0,n,i,i+1,j))
            {
                a[i]=j+'a';
                break;
            }
        }
    }
    printf("%s\n",a);
    return 0; 
}