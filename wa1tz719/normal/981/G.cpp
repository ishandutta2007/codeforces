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
struct node
{
    bool val;
    node * ch[2];
};
node * null;
node * new_node()
{
    static node a[20000005];
    static int top=0;
    a[top].val=0;
    a[top].ch[0]=null;
    a[top].ch[1]=null;
    return &a[top++];
}
void change(int l,int r,int l0,int r0,node * &k)
{
    if (k==null)
    {
        k=new_node();
    }
    if ((l0<=l)&&(r<=r0))
    {
        k->val=true;
        k->ch[0]=k;
        k->ch[1]=k;
        return;
    }
    int mid=(l+r)/2;
    if (l0<mid) change(l,mid,l0,r0,k->ch[0]);
    if (mid<r0) change(mid,r,l0,r0,k->ch[1]);
    k->val=k->ch[0]->val&k->ch[1]->val;
}
const int modo=998244353;
int val[1<<20];
int tag[1<<20];
int mul_tag[1<<20];
void push_down(int num,int l,int r)
{
    if (mul_tag[num]!=1)
    {
        mul_tag[num*2+1]=(long long)mul_tag[num*2+1]*mul_tag[num]%modo;
        tag[num*2+1]=(long long)tag[num*2+1]*mul_tag[num]%modo;
        val[num*2+1]=(long long)val[num*2+1]*mul_tag[num]%modo;
        mul_tag[num*2+2]=(long long)mul_tag[num*2+2]*mul_tag[num]%modo;
        tag[num*2+2]=(long long)tag[num*2+2]*mul_tag[num]%modo;
        val[num*2+2]=(long long)val[num*2+2]*mul_tag[num]%modo;
        mul_tag[num]=1;
    }
    if (tag[num]!=0)
    {
        tag[num*2+1]=tag[num*2+1]+tag[num];
        if (tag[num*2+1]>=modo) tag[num*2+1]-=modo;
        tag[num*2+2]=tag[num*2+2]+tag[num];
        if (tag[num*2+2]>=modo) tag[num*2+2]-=modo;
        int mid=(l+r)/2;
        val[num*2+1]=(val[num*2+1]+(long long)(mid-l)*tag[num])%modo;
        val[num*2+2]=(val[num*2+2]+(long long)(r-mid)*tag[num])%modo;
        tag[num]=0;
    }
}
void change2(int num,int l,int r,int l0,int r0,node * now)
{
    if ((l0<=l)&&(r<=r0))
    {
        if (now->val)
        {
            tag[num]*=2;
            if (tag[num]>=modo) tag[num]-=modo;
            val[num]*=2;
            if (val[num]>=modo) val[num]-=modo;
            mul_tag[num]*=2;
            if (mul_tag[num]>=modo) mul_tag[num]-=modo;
            return;
        }
        else if (now==null)
        {
            tag[num]++;
            if (tag[num]>=modo) tag[num]-=modo;
            val[num]+=(r-l);
            if (val[num]>=modo) val[num]-=modo;
            return;
        }
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    if (l0<mid) change2(num*2+1,l,mid,l0,r0,now->ch[0]);
    if (mid<r0) change2(num*2+2,mid,r,l0,r0,now->ch[1]);
    val[num]=(val[num*2+1]+val[num*2+2])%modo;
}
int query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return val[num];
    }
    int mid=(l+r)/2;
    int ans=0;
    push_down(num,l,r);
    if (l0<mid) ans+=query(num*2+1,l,mid,l0,r0);
    if (mid<r0) ans+=query(num*2+2,mid,r,l0,r0);
    if (ans>=modo) ans-=modo;
    return ans;
}
node * root[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,q;
    int i;
    scanf("%d%d",&n,&q);
    null=new_node();
    null->ch[0]=null;
    null->ch[1]=null;
    for (i=1;i<=n;i++)
    {
        root[i]=null;
    }
    for (i=0;i<(1<<20);i++)
    {
        mul_tag[i]=1;
    }
    for (i=0;i<q;i++)
    {
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            l--;
            change2(0,0,n,l,r,root[x]);
            change(0,n,l,r,root[x]);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l--;
            printf("%d\n",query(0,0,n,l,r));
        }
    }
    return 0;
}