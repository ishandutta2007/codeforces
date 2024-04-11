//CF1656G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,m,a[N],b[N],c[N],f[N],p[N],r[N];
void st(int x,int y){
	p[x]=y;
	r[y]=x;
}
void go(int x){
	if(p[x])
		return;
	int y=f[x];
	st(x,y);
	st(y,n+1-y);
	go(n+1-y);
}
void mrg(int x,int y){
	int x1=r[x],x2=r[n+1-x],y1=r[y],y2=r[n+1-y];
	st(x1,y);
	st(x2,n+1-y);
	st(y1,n+1-x);
	st(y2,x);
}
int main()
{
	int T,i,j,x,y,z,o,u;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			b[i]=0,p[i]=0,r[i]=0,f[i]=0,c[i]=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),b[a[i]]++;
		x=0;
		for(i=1;i<=n;i++)
			if(b[i]%2==1)
				x++,y=i;
		if(x>=2){
			printf("NO\n");
			continue;
		}
		if(n%2==1){
			if(x!=1){
				printf("NO\n");
				continue;
			}
			if(b[y]==1&&a[(n+1)/2]==y){
				printf("NO\n");
				continue;
			}
			for(i=1;i<=n;i++)
				if(a[i]==y&&i!=(n+1)/2)
					z=i;
			a[z]=n+1;
		}
		else
			z=0;
		m=0;
		for(i=1;i<=n;i++){
			if(i==z)
				continue;
			if(c[a[i]])
				f[i]=c[a[i]],f[c[a[i]]]=i,c[a[i]]=0;
			else
				c[a[i]]=i;
		}
		o=0;
		if(n%2==1)
			p[z]=(n+1)/2,r[(n+1)/2]=z,go((n+1)/2),o=1,u=z;
		for(i=1;i<=n;i++){
			if(!p[i]){
				go(i);
				if(o){
					mrg(u,i);
				}
				else{
					u=i;
					o=1;
				}
			}
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
			printf("%d ",r[i]);
			//printf("%d",a[r[i]]);
		printf("\n");
	}
	return 0;
}