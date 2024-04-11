#include<bits/stdc++.h>
using namespace std;
struct juice
{
    int w;
    int s[4];
}a[1005];
int n;
int used[4];
int ans=300003;
bool cmp()
{
    for(int i=0;i<3;++i)
    {
        if(used[i]==0)
        	return false;
    }
    return true;
}
void dfs(int l,int sum,int dep)
{
//	printf("%d %d %d\n",l,sum,dep);
    if(dep==3)
    {
        if(cmp()==true&&sum<ans)
        {
            ans=sum;
        }
        return ;
    }
    if(cmp()==true)
    {
        if(sum<ans)
        {
            ans=sum;
        }
        return ;
    }
    if(sum>ans)
    {
        return ;
    }
    for(int i=l+1;i<=n;++i)
    {
    	for(int j=0;j<3;j++)
    	{
    		if(a[i].s[j]==1)
    		{
    			used[j]++;
			}
		}
        dfs(i,sum+a[i].w,dep+1);
        for(int j=0;j<3;j++)
    	{
    		if(a[i].s[j]==1)
    		{
    			used[j]--;
			}
		}
    }
}
int main()
{
    char x;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i].w);
        x=getchar();
        while(x!='A'&&x!='B'&&x!='C')
        {
            x=getchar();
        }
        while(x=='A'||x=='B'||x=='C')
        {
            a[i].s[x-'A']=1;
            x=getchar();
        }
    }
    dfs(0,0,0);
    if(ans==300003)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",ans);
    }
}
//saeoutcdirgfiopjtryiufetry