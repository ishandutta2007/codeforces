#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int q[210],te[210],map[220][220],in[220],out[220],dn[220];
int i,j,k,n,m,top,tail,ct,tn,num,id;
int main()
{
	while(~scanf("%d",&n))
	{
		m=n*(n-1)/2;
		memset(map,0,sizeof(map));
		memset(in,0,sizeof(in));
		for(i=0;i<m;i++)
		{
			scanf("%d",&num);
			for(j=0;j<num;j++)
			{scanf("%d",&te[j]);in[te[j]]=1;}
			for(j=0;j<num;j++)
			for(k=j+1;k<num;k++)
			map[te[j]][te[k]]++,map[te[k]][te[j]]++;
		}
		if(n==2)
		{
			printf("1 %d\n",te[0]);
			printf("%d",num-1);
			for(i=1;i<num;i++)
			printf(" %d",te[i]);puts("");
			continue;
		}
		ct=0;
		memset(dn,0,sizeof(dn));
		while(ct<n)
		{
			tn=0;
			for(i=1;i<=200;i++)
			if(in[i]&&!dn[i]){id=i;break;}
			ct++;
			tn=1;
			out[0]=id;
			top=0;tail=1;
			q[1]=id;dn[id]=1;
			while(top<tail)
			{
				top++;
				i=q[top];
				for(j=1;j<=200;j++)
				{
					if(in[j]&&map[i][j]>1&&!dn[j])
					{
						tail++;
						q[tail]=j;
						dn[j]=1;
						out[tn++]=j;
					}
				}
			}
			printf("%d",tn);
			for(i=0;i<tn;i++)printf(" %d",out[i]);puts("");
		}
	}
}