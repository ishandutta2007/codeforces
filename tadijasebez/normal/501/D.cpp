#include <stdio.h>
const int N=200050;
int BIT[N];
void Init(){ for(int i=0;i<N;i++) BIT[i]=0;}
void Set(int i, int f){ for(;i<N;i+=i&-i) BIT[i]+=f;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int a[N];
int main()
{
	int n,i,x,l,o=2,j;
	scanf("%i",&n);
	for(i=1,l=0;i<n;i<<=1,l++);
	while(o--)
	{
		Init();
		for(i=1;i<=n;i++)
		{
			scanf("%i",&x);
			a[i]+=x;
			a[i]-=Get(x+1);
			Set(x+1,1);
		}
	}
	for(i=n;i;i--) a[i-1]+=a[i]/(n-i+1),a[i]%=n-i+1;
	int s;
	for(i=1;i<=n;i++)
	{
		for(s=0,j=l;~j;j--) if((s+(1<<j))<=n && BIT[s+(1<<j)]<=a[i]) a[i]-=BIT[s+(1<<j)],s+=1<<j;
		printf("%i ",s);
		Set(s+1,-1);
	}
	return 0;
}