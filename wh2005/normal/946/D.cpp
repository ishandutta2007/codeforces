#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
char s[509];
int a[509][509],b[509];
int f[509][509],w[509][509];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s);b[i]=0;
		for(int j=0;j<m;j++){
			if(s[j]=='1') a[i][++b[i]]=j+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(k,b[i]);j++){
			if(j==b[i]){w[i][j]=a[i][b[i]]-a[i][1]+1;continue;}
			for(int p=0;p<=j;p++){
				w[i][j]=max(w[i][j],a[i][p+1]-a[i][1]+a[i][b[i]]-a[i][b[i]+p-j]);
			}
		}
	}
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int p=0;p<=min(j,b[i]);p++)
				if(f[i-1][j-p]!=-1) f[i][j]=max(f[i][j],f[i-1][j-p]+w[i][p]);
		}
	}
	int ans=0,da=0;
	for(int i=1;i<=n;i++)
		if(b[i]) ans+=a[i][b[i]]-a[i][1]+1;
	for(int i=0;i<=k;i++) da=max(da,f[n][i]);
	printf("%d\n",ans-da);	
	return 0;
}