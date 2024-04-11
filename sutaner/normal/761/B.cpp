#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 10005
using namespace std;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
		c[i]=a[i]-a[i-1];
	c[0]=l+a[0]-a[n-1];
	for(int i=1;i<n;i++)
		d[i]=b[i]-b[i-1];
	d[0]=l+b[0]-b[n-1];
	bool flag=false;
	for(int i=0;i<n;i++){
		if(c[0]!=d[i])continue;
		flag=true;
		for(int j=0;j<n;j++)
			if(c[j]!=d[(i+j)%n]){
				flag=false;
				break;
			}
		if(flag)break;
	}
	if(flag)printf("YES");
	else printf("NO");
	return 0;
}