#include <stdio.h>
#include <cstring>
#define ll long long
void MoveUp(ll &x, int n)
{
	int k=1;
	ll y=x;
	while(!(y&1)) k++,y>>=1;
	y>>=1;
	if(k==n) return;
	if(y&1) x-=1ll<<(k-1);
	else x+=1ll<<(k-1);
}
void MoveLeft(ll &x, int n)
{
	int k=1;
	ll y=x;
	while(!(y&1)) k++,y>>=1;
	y>>=1;
	if(k==1) return;
	x-=1ll<<(k-2);
}
void MoveRight(ll &x, int n)
{
	int k=1;
	ll y=x;
	while(!(y&1)) k++,y>>=1;
	y>>=1;
	if(k==1) return;
	x+=1ll<<(k-2);
}
char ch[100050];
int main()
{
	ll m,x;
	int n,q,l,i;
	scanf("%lld %i",&m,&q);
	n=0;while(m) n++,m>>=1;
	while(q--)
	{
		scanf("%lld",&x);
		scanf("%s",ch);
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			if(ch[i]=='U') MoveUp(x,n);
			if(ch[i]=='L') MoveLeft(x,n);
			if(ch[i]=='R') MoveRight(x,n);
			//printf("%lld ",x);
		}
		printf("%lld\n",x);
	}
	return 0;
}