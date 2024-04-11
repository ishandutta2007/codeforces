#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int x[10],y[10];
inline bool check(int a,int b,int c,int d)
{
	int lab=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
	int lac=(x[a]-x[c])*(x[a]-x[c])+(y[a]-y[c])*(y[a]-y[c]);
	int lbc=(x[b]-x[c])*(x[b]-x[c])+(y[b]-y[c])*(y[b]-y[c]);
	if(lab+lac==lbc&&lab==lac&&x[d]==x[b]+x[c]-x[a]&&y[d]==y[b]+y[c]-y[a]) return true;
	if(lab+lbc==lac&&lab==lbc&&x[d]==x[a]+x[c]-x[b]&&y[d]==y[a]+y[c]-y[b]) return true;
	if(lac+lbc==lab&&lac==lbc&&x[d]==x[b]+x[a]-x[c]&&y[d]==y[b]+y[a]-y[c]) return true;
	return false;
}
inline bool check1(int a,int b,int c,int d)
{
	int lab=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
	int lac=(x[a]-x[c])*(x[a]-x[c])+(y[a]-y[c])*(y[a]-y[c]);
	int lbc=(x[b]-x[c])*(x[b]-x[c])+(y[b]-y[c])*(y[b]-y[c]);
	if(lab+lac==lbc&&x[d]==x[b]+x[c]-x[a]&&y[d]==y[b]+y[c]-y[a]) return true;
	if(lab+lbc==lac&&x[d]==x[a]+x[c]-x[b]&&y[d]==y[a]+y[c]-y[b]) return true;
	if(lac+lbc==lab&&x[d]==x[b]+x[a]-x[c]&&y[d]==y[b]+y[a]-y[c]) return true;
	return false;
}
int main()
{
	for(int i=1;i<=8;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=8;i++)
		for(int j=i+1;j<=8;j++)
			for(int k=j+1;k<=8;k++)
				for(int l=k+1;l<=8;l++)
					if(check(i,j,k,l))
					{
						bool vis[10]={0};
						int r[5],cnt=0;
						vis[i]=vis[j]=vis[k]=vis[l]=1;
						for(int m=1;m<=8;m++)
							if(!vis[m])
								r[++cnt]=m;
						if(check1(r[1],r[2],r[3],r[4]))
						{
							printf("YES\n");
							printf("%d %d %d %d\n",i,j,k,l);
							printf("%d %d %d %d\n",r[1],r[2],r[3],r[4]);
							return 0;
						}
					}
	printf("NO\n");
	return 0;
}