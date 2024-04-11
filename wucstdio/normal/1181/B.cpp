#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100005],n,ans[100005],res[100005],num1,num2;
inline int read()
{
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	return c-'0';
}
void check()
{
	if(num1>num2)
	{
		num1=num2;
		for(int i=1;i<=num2;i++)ans[i]=res[i];
		return;
	}
	if(num1<num2)return;
	for(int i=1;i<=num1;i++)
	{
		if(ans[i]>res[i])
		{
			num1=num2;
			for(int i=1;i<=num2;i++)ans[i]=res[i];
			return;
		}
		if(ans[i]<res[i])return;
	}
}
int tmp[100005],top;
void calc(int pos)
{
	memset(res,0,sizeof(res));
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=pos;i++)res[pos-i+1]=a[i];
	num2=pos;
	int x=pos+1;
	while(a[x]==0&&x<=n)x++;
	top=n-x+1;
	for(int i=x;i<=n;i++)tmp[top-(i-x)]=a[i];
//	for(int i=1;i<=num2;i++)printf("%d",res[i]);
//	printf(" ");
//	for(int i=1;i<=top;i++)printf("%d",tmp[i]);
//	printf("\n");
	num2=max(num2,top);
	for(int i=1;i<=num2;i++)res[i]+=tmp[i];
	res[num2+1]=0;
	for(int i=1;i<=num2;i++)
	  res[i+1]+=res[i]/10,res[i]%=10;
	if(res[num2+1])num2++;
	for(int i=1;i<=num2/2;i++)swap(res[i],res[num2-i+1]);
	check();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i]=read();
	num1=1000000;
	int pos=n/2;
	while(pos&&a[pos]==0)pos--;
	pos--;
	if(pos)calc(pos);
	pos=n/2;
	while(pos<=n&&a[pos]==0)pos++;
	pos--;
	if(pos<n)calc(pos);
	pos=n/2+1;
	while(pos&&a[pos]==0)pos--;
	pos--;
	if(pos)calc(pos);
	pos=n/2+1;
	while(pos<=n&&a[pos]==0)pos++;
	pos--;
	pos=n/2+2;
	while(pos&&a[pos]==0)pos--;
	pos--;
	if(pos)calc(pos);
	pos=n/2+2;
	while(pos<=n&&a[pos]==0)pos++;
	pos--;
	pos=n/2+3;
	while(pos&&a[pos]==0)pos--;
	pos--;
	if(pos)calc(pos);
	pos=n/2+3;
	while(pos<=n&&a[pos]==0)pos++;
	pos--;
	if(pos<n)calc(pos);
	for(int i=1;i<=num1;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}