//CF1086C
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
const int N = 1e6+16;
int n,k,f,p[33],w[33];
char s[N],a[N],b[N];
void ans(){
	f=1;
	printf("YES\n");
	int i=1,j=1;
	while(i<=k){
		while(p[i]){
			i++;
		}
		while(w[j]){
			j++;
		}
		p[i]=j;
		w[j]=i;
	}
	for(i=1;i<=k;i=i+1)
		printf("%c",p[i]+96);
	printf("\n");
}
void solve(int u,int aa,int bb){
	//cout<<u<<aa<<bb<<endl;
	if(f)
		return;
	if(u==n+1){
		ans();
		return;
	}
	if(!aa&&!bb){
		ans();
		return;
	}
	int i,c=s[u]-96,x,y,z;
	for(i=1;i<=k;i=i+1){
		if(p[c]&&p[c]!=i)
			continue;
		if(w[i]&&w[i]!=c)
			continue;
		if(aa&&i+96<a[u])
			continue;
		if(bb&&b[u]<i+96)
			continue;
		x=aa&&(i+96==a[u]);
		y=bb&&(i+96==b[u]);
		if(!p[c]){
			p[c]=i;
			w[i]=c;
			z=1;
		}
		else
			z=0;
		solve(u+1,x,y);
		if(z){
			p[c]=0;
			w[i]=0;
		}
	}
}
int main()
{
	int tc,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%s%s%s",&k,s+1,a+1,b+1);
		n=strlen(s+1);
		f=0;
		solve(1,1,1);
		if(!f)
			printf("NO\n");
		for(i=0;i<=32;i=i+1)
			p[i]=0,w[i]=0;
	}
	return 0;
}