#include<stdio.h>
#include<map>
using namespace std;
map<int,int>g[100020];
int n,v,c,l,r,z,ss,p[100020],f[100020],s[100020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&v,&c,&l,&r);
		if(r+c<100010&&(!l||g[l].count(r+c)))
		{
			int u=g[l][r+c];
			f[i]=f[u]+v,p[i]=u;
			if(r==0&&f[i]>f[z])
				z=i;
			if(f[i]>f[g[l+c][r]])
				g[l+c][r]=i;
		}
	}
	for(;z;z=p[z])
		s[ss++]=z;
	printf("%d\n",ss);
	for(;ss--;)
		printf("%d ",s[ss]);
	return 0;
}