#include <bits/stdc++.h>
using namespace std;
#define Maxn 1000007
int n,res=0;
pair<int,int> ans[Maxn];
int a[Maxn],pos[Maxn];
void fix(int i,int j)
{
    pos[a[i]]=j;
    pos[a[j]]=i;
    swap(a[i],a[j]);
    ans[++res]=make_pair(i,j);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    for (int i=2;i<n;i++)
        if (a[i]!=i)
        {
            if (abs(pos[i]-i)>=n/2) fix(pos[i],i);
            else if (abs(pos[i]-1)>=n/2)
            {
                if (abs(i-1)>=n/2) fix(1,pos[i]),fix(1,i);
                else fix(1,pos[i]),fix(1,n),fix(n,i);
            }
            else 
            {
                if (abs(i-1)>=n/2) fix(n,pos[i]),fix(1,n),fix(1,i);
                else fix(n,pos[i]),fix(n,i);
            }
        }
    if (a[1]!=1) fix(1,n);
    printf("%d\n",res);
    for (int i=1;i<=res;i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}