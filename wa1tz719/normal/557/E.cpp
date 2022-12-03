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
char a[5005];
bool dp[5005][5005][2];
bool visit[5005][5005];
void dfs(int l,int r)
{
    if (visit[l][r]) return;
    visit[l][r]=true;
    if (l==r-1)
    {
        dp[l][r][0]=true;
        dp[l][r][1]=true;
    }
    else if (l==r-2)
    {
        dp[l][r][1]=true;
        if (a[l]==a[r-1])
        {
            dp[l][r][0]=true;
        }
        else
        {
            dp[l][r][0]=false;
        }
    }
    else
    {
        dfs(l+1,r-1);
        dp[l][r][0]=dp[l+1][r-1][1];
        if (a[l]!=a[r-1])
        {
            dp[l][r][0]=false;
        }
        dp[l][r][1]=dp[l+1][r-1][0];
    }
}
struct node
{
    int size;
    node * ch[2];
};
node * null;
node * new_node()
{
    static node a[16000005];
    static int top=0;
    a[top].size=0;
    a[top].ch[0]=null;
    a[top].ch[1]=null;
    return &a[top++];
}
void dfs2(node * t)
{
    if (t==null) return;
    dfs2(t->ch[0]);
    dfs2(t->ch[1]);
    t->size+=t->ch[0]->size+t->ch[1]->size;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    null=new_node();
    null->ch[0]=null;
    null->ch[1]=null;
    scanf("%s",a);
    int n;
    int m;
    scanf("%d",&m);
    n=strlen(a);
    int i;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=i+1;j<=n;j++)
        {
            dfs(i,j);
        }
    }
    node * root;
    root=new_node();
    for (i=0;i<n;i++)
    {
        node * t=root;
        int j;
        for (j=i+1;j<=n;j++)
        {
            if (t->ch[a[j-1]-'a']==null) t->ch[a[j-1]-'a']=new_node();
            t=t->ch[a[j-1]-'a'];
            if (dp[i][j][0]) t->size++;
        }
    }
    dfs2(root);
    node * now=root;
    for (;;)
    {
        int t1=now->ch[0]->size;
        int t3=now->ch[1]->size;
        int t2=now->size-t1-t3;
        if (m<=t2)
        {
            break;
        }
        else if (m<=t1+t2)
        {
            putchar('a');
            now=now->ch[0];
            m-=t2;
        }
        else
        {
            putchar('b');
            now=now->ch[1];
            m-=t1;
            m-=t2;
        }
    }
    return 0;
}