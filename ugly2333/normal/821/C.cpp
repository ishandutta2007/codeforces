// CF 821C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int st[333333],f[333333];
int main()
{
	int n,sz,i,x,ans,p;
	char c[11];
	scanf("%d",&n);
	ans=0;
	sz=0;
	p=0;
	for(i=1;i<=n+n;i=i+1)
	{
		scanf("%s",&c);
		if(c[0]=='a'){
			scanf("%d",&x);
			sz++;
			st[sz]=x;
			f[x]=1;
		}
		else{
			p++;
			if(st[sz]!=p&&(f[p]!=2||sz>0)){
				ans++;
				while(sz>0){
					f[st[sz]]=2;
					sz--;
				}
			}
			f[p]=3;
			if(sz==0)
				continue;
			st[sz]=0;
			sz--;
		}
	}
	printf("%d\n",ans);
	return 0;
}