#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define ll long long
using namespace std;
ll a,b,c;
int cur;
ll find(int x)
{
	if(x==1)return min(min(a,b),c);
	if(x==3)return max(max(a,b),c);
	ll aa=a,bb=b,cc=c;
	if(aa>bb)swap(aa,bb);
	if(bb>cc)swap(bb,cc);
	if(aa>bb)swap(aa,bb);
	return bb;
}
ll gap(int x)
{
	if(x==1)return find(2)-find(1);
	else return find(3)-find(2);
}
bool check(int cur)
{
	ll aa=a,bb=b,cc=c;
	if(cur==2)swap(aa,bb);
	if(cur==3)swap(aa,cc);
	return (bb<aa)+(cc<aa)==1;
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("First\n");
	fflush(stdout);
	ll v=1e11;
	printf("%lld\n",v);
	fflush(stdout);
	scanf("%d",&cur);
	switch(cur)
	{
		case 1:a+=v;break;
		case 2:b+=v;break;
		case 3:c+=v;break;
	}
	printf("%lld\n",v=find(3)*2-find(2)-find(1));
	fflush(stdout);
	scanf("%d",&cur);
	switch(cur)
	{
		case 1:a+=v;break;
		case 2:b+=v;break;
		case 3:c+=v;break;
	}
	printf("%lld\n",gap(1));
	return 0;
}