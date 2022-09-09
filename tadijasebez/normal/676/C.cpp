#include <stdio.h>
#include <cstring>
const int N=100050;
const int M=20*N;
int x[M],ls[M],rs[M],a,b,clock;
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock;
	x[c]++;
	if(ss==se) return ;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int sol;
char word[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	scanf("%s",&word);
	for(i=0;i<n;i++)
	{
		if(word[i]=='a') Set(a,0,n,i);
		if(word[i]=='b') Set(b,0,n,i);
	}
	int top,bot,mid;
	for(i=0;i<n;i++)
	{
		top=n-1;
		bot=i;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(a,0,n,i,mid)>k) top=mid-1;
			else sol=max(sol,mid-i+1),bot=mid+1;
		}
		top=n-1;
		bot=i;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(b,0,n,i,mid)>k) top=mid-1;
			else sol=max(sol,mid-i+1),bot=mid+1;
		}
	}
	printf("%i\n",sol);
	return 0;
}