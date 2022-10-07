#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,p[300005],pos[300005],from[2000005],to[2000005],tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(pos[i]==i)continue;
		if(2*(pos[i]-i)>=n)
		{
			from[++tot]=i;
			to[tot]=pos[i];
			int x=pos[i];
			swap(p[x],p[i]);
			swap(pos[p[x]],pos[p[i]]);
		}
		else
		{
			if(i<=n/2)
			{
				int x=pos[i];
				if(x>n/2)
				{
					from[++tot]=1;
					to[tot]=x;
					swap(p[x],p[1]);
					swap(pos[p[x]],pos[p[1]]);
					from[++tot]=1;
					to[tot]=n;
					swap(p[1],p[n]);
					swap(pos[p[1]],pos[p[n]]);
					from[++tot]=i;
					to[tot]=n;
					swap(p[i],p[n]);
					swap(pos[p[i]],pos[p[n]]);
					from[++tot]=1;
					to[tot]=x;
					swap(p[1],p[x]);
					swap(pos[p[1]],pos[p[x]]);
				}
				else
				{
					from[++tot]=x;
					to[tot]=n;
					swap(p[x],p[n]);
					swap(pos[p[x]],pos[p[n]]);
					from[++tot]=i;
					to[tot]=n;
					swap(p[i],p[n]);
					swap(pos[p[i]],pos[p[n]]);
				}
			}
			else
			{
				int x=pos[i];
				from[++tot]=1;
				to[tot]=x;
				swap(p[1],p[x]);
				swap(pos[p[1]],pos[p[x]]);
				from[++tot]=1;
				to[tot]=i;
				swap(p[1],p[i]);
				swap(pos[p[1]],pos[p[i]]);
				from[++tot]=1;
				to[tot]=x;
				swap(p[1],p[x]);
				swap(pos[p[1]],pos[p[x]]);
			}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d %d\n",from[i],to[i]);
	return 0;
}