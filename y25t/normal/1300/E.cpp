#include<cstdio>
#define ll long long
#define lf double
#define N 1000005

int n;
ll a[N];

int st[N],top;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	st[++top]=0;
	for(int i=1;i<=n;i++){
		while(top>1&&(a[i]-a[st[top]])*(st[top]-st[top-1])<(a[st[top]]-a[st[top-1]])*(i-st[top]))
			top--;
		st[++top]=i;
	}
	for(int i=1;i<top;i++)
		for(int j=st[i]+1;j<=st[i+1];j++)
			printf("%.9lf\n",(lf)(a[st[i+1]]-a[st[i]])/(lf)(st[i+1]-st[i]));
}