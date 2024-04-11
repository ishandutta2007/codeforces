#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[70005][15];
struct node
{
    bool only_tag;
    bool this_tag;
    node * ch[10];
};
node * new_node()
{
    static node a[1000005];
    static int top=0;
    memset(a[top].ch,0,sizeof(a[top].ch));
    a[top].only_tag=false;
    a[top].this_tag=false;
    return &a[top++];
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",&a[i]);
    }
    node * root=new_node();
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<9;j++)
        {
            node * now=root;
            int k;
            for (k=j;k<9;k++)
            {
                if (now->ch[a[i][k]-'0']==0)
                {
                    now->ch[a[i][k]-'0']=new_node();
                    now->ch[a[i][k]-'0']->only_tag=true;
                    now->ch[a[i][k]-'0']->this_tag=true;
                }
                now=now->ch[a[i][k]-'0'];
                if ((now->only_tag)&&(!now->this_tag))
                {
                    now->only_tag=false;
                }
            }
        }
        for (j=0;j<9;j++)
        {
            node * now=root;
            int k;
            for (k=j;k<9;k++)
            {
                now=now->ch[a[i][k]-'0'];
                now->this_tag=false;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        string ans=a[i];
        for (j=0;j<9;j++)
        {
            int k;
            node * now=root;
            for (k=j;k<9;k++)
            {
                now=now->ch[a[i][k]-'0'];
                if (now->only_tag) break;
            }
            if (now->only_tag)
            {
                if (k-j<ans.size())
                {
                    ans="";
                    int t;
                    for (t=j;t<=k;t++)
                    {
                        ans+=a[i][t];
                    }
                }
            }
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}