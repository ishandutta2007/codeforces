#include <cstdio>

int n,m,a[100000],b[100000];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int j=0;j<m;j++) scanf("%d",b+j);

	int as=0,bs=0,i=0,j=0,ans=0;
	while(i<n ||  j<m) {
		if(i<n && (j==m || as+a[i] < bs+b[j])) as+=a[i++];
		else bs+=b[j++];
		if(as==bs) ans++;
	}
	printf("%d\n",ans);
	
	return 0;
}