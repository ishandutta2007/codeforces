#include <stdio.h>
#include <vector>
using namespace std;
const int M=1000000;
const int N=300050;
const int inf=1000000007;
int x[M],rs[M],ls[M],clock,root;
void Set(int &c, int ss, int se, int qi, int val)
{
    if(!c) c=++clock;
    //x[c]+=val;
    if(ss==se)
    {
        x[c]+=val;
        return;
    }
    int mid=ss+se>>1;
    if(qi<=mid) Set(ls[c],ss,mid,qi,val);
    else Set(rs[c],mid+1,se,qi,val);
    x[c]=max(x[rs[c]],x[ls[c]]);
}
vector<int> Tree[N];
int a[N];
int sol=inf;
int main()
{
    int n,i,u,v,j;
    scanf("%i",&n);
    for(i=1;i<=n;i++) scanf("%i",&a[i]),Set(root,1,n,i,a[i]+2);
    for(i=1;i<n;i++)
    {
        scanf("%i %i",&u,&v);
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        Set(root,1,n,i,-2);
        for(j=0;j<Tree[i].size();j++)
        {
            v=Tree[i][j];
            Set(root,1,n,v,-1);
        }
        sol=min(sol,x[root]);
        Set(root,1,n,i,2);
        for(j=0;j<Tree[i].size();j++)
        {
            v=Tree[i][j];
            Set(root,1,n,v,1);
        }
    }
    printf("%i\n",sol);
    return 0;
}