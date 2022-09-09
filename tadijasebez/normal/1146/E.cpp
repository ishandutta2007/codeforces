#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=600050;
const int M=2*N;
const int lim=100050;
int ls[M],rs[M],tsz,root,val[M],xr[M];
int lzy[M];
void push(int c, int ss, int se)
{
	if(lzy[c]==-1)
	{
		if(xr[c])
		{
			val[ls[c]]^=1;
			val[rs[c]]^=1;
			if(lzy[ls[c]]!=-1) lzy[ls[c]]^=1;
			else xr[ls[c]]^=1;
			if(lzy[rs[c]]!=-1) lzy[rs[c]]^=1;
			else xr[rs[c]]^=1;
			xr[c]=0;
		}
	}
	else
	{
		//printf("push:%i %i %i %i\n",c,ss,se,lzy[c]);
		lzy[ls[c]]=val[ls[c]]=lzy[c];
		xr[ls[c]]=0;
		lzy[rs[c]]=val[rs[c]]=lzy[c];
		xr[rs[c]]=0;
		lzy[c]=-1;
	}
}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	lzy[c]=-1;
	val[c]=0;
	//if(tsz<100) printf("%i ",lzy[c]);
	//if(c==1) printf("%i %i\n",c,lzy[c]);
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qs, int qe, int f)
{
	//if(c==1) printf("%i %i\n",qs,qe);
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ val[c]=lzy[c]=f;xr[c]=0;return;}
	int mid=ss+se>>1;
	push(c,ss,se);
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
}
void Xor(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		if(lzy[c]!=-1) lzy[c]^=1;
		else xr[c]^=1;
		val[c]^=1;
		return;
	}
	int mid=ss+se>>1;
	push(c,ss,se);
	Xor(ls[c],ss,mid,qs,qe);
	Xor(rs[c],mid+1,se,qs,qe);
}
int Get(int c, int ss, int se, int qi)
{
	//if(ss==se) printf("get:%i %i %i\n",ss,qi,val[c]);
	if(ss==se) return val[c];
	push(c,ss,se);
	int mid=ss+se>>1;
	if(qi<=mid) return Get(ls[c],ss,mid,qi);
	else return Get(rs[c],mid+1,se,qi);
}
int a[N];
int main()
{
	int n,q,i,x;
	char t;
	scanf("%i %i",&n,&q);
	Build(root,-lim,lim);
	//for(i=1;i<100;i++) printf("%i ",lzy[i]);
	//printf("lzy[1]:%i\n",lzy[1]);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	while(q--)
	{
		scanf("\n%c %i",&t,&x);
        if(t=='>' && x>=0)
		{
			Set(root,-lim,lim,x+1,lim,1);
			Set(root,-lim,lim,-lim,-x-1,0);
		}
		else if(t=='<' && x<=0)
		{
			Set(root,-lim,lim,-lim,x-1,1);
			Set(root,-lim,lim,-x+1,lim,0);
		}
		else if(t=='>')
		{
			Set(root,-lim,lim,-lim,x,0);
			Set(root,-lim,lim,-x,lim,1);
			Xor(root,-lim,lim,x+1,-x-1);
		}
		else if(t=='<')
		{
			Set(root,-lim,lim,-lim,-x,1);
			Set(root,-lim,lim,x,lim,0);
			Xor(root,-lim,lim,-x+1,x-1);
		}
		/*for(i=1;i<=n;i++)
		{
			int s=Get(root,-lim,lim,a[i]);
			if(s) printf("%i ",-a[i]);
			else printf("%i ",a[i]);
		}
		printf("\n");*/
	}
	for(i=1;i<=n;i++)
	{
		int s=Get(root,-lim,lim,a[i]);
		if(s) printf("%i ",-a[i]);
		else printf("%i ",a[i]);
	}
	return 0;
}