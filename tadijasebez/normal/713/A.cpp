#include <stdio.h>
#define ll long long
const int N=100050;
const int M=N*18;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int p, ll num, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(!p) return;
	int y=num%10;
	num/=10;
	if(y%2==0) Set(ls[c],p-1,num,val);
	else Set(rs[c],p-1,num,val);
}
int Get(int c, int p, ll num)
{
	if(!p) return x[c];
	int y=num%10;
	num/=10;
	if(y%2==0) return Get(ls[c],p-1,num);
	else return Get(rs[c],p-1,num);
}
ll k;
int main()
{
	int q;
	char t;
	scanf("%i",&q);
	while(q --> 0)
	{
		scanf("\n%c %lld",&t,&k);
		if(t=='+') Set(root,18,k,1);
		if(t=='-') Set(root,18,k,-1);
		if(t=='?') printf("%i\n",Get(root,18,k));
	}
	return 0;
}