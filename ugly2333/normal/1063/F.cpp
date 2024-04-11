//CF1063F
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
const int N = 500005;
char ch[N];
int n,a[N],h[N],c[N][27],p[N];
bool f[N],g[N];
int main()
{
	int i,j,x,u,o;
	scanf("%d%s",&n,ch+1);
	for(i=1;i<=n;i=i+1)
		a[i]=ch[i]-'a'+1;
	for(i=1;i<=n;i=i+1)
		f[i]=i,h[i]=a[i];
	u=n;
	for(j=2;1;j=j+1){
		memset(g,0,sizeof(g));
		memset(p,0,sizeof(p));
		for(i=u;i;i=i-1){
			if(f[i]){
				if(p[h[i]]>=i+j-1){
					g[i-1]=1;
					if(p[h[i]]>=i+j)
						g[i]=1;
				}
				if(!p[h[i]])
					p[h[i]]=i;
			}
		}
		x=0;
		for(i=1;i<=u;i=i+1){
			f[i]=g[i];
			if(f[i])
				x=1,o=i;
			c[h[i]][a[i+j-1]]=i;
		}
		if(!x){
			cout<<j-1;
			return 0;
		}
		u=o;
		for(i=1;i<=u;i=i+1)
			h[i]=c[h[i]][a[i+j-1]];
	}
	return 0;
}