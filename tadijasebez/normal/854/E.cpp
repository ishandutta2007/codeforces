#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=20*N;
int root[N],ls[M],rs[M],tsz,sum[M];
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+1;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p, int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return sum[c]-sum[p];
	int mid=ss+se>>1;
	return Get(ls[p],ls[c],ss,mid,qs,qe)+Get(rs[p],rs[c],mid+1,se,qs,qe);
}
int n,q,x,x1,y1,x2,y2;
int Get(int x1, int y1, int x2, int y2){ return Get(root[y1-1],root[y2],1,n,x1,x2);}
int main()
{
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++) scanf("%i",&x),Set(root[i-1],root[i],1,n,x);
	while(q--)
	{
		scanf("%i %i %i %i",&y1,&x1,&y2,&x2);
		ll T1=Get(1   ,1   ,x1-1,y1-1),T2=Get(x1  ,1   ,x2  ,y1-1),T3=Get(x2+1,1   ,n   ,y1-1),
		   T4=Get(1   ,y1  ,x1-1,y2  ),T5=Get(x1  ,y1  ,x2  ,y2  ),T6=Get(x2+1,y1  ,n   ,y2  ),
		   T7=Get(1   ,y2+1,x1-1,n   ),T8=Get(x1  ,y2+1,x2  ,n   ),T9=Get(x2+1,y2+1,n   ,n   );
		ll ans=T1*(T5+T8+T6+T9)+T2*(T4+T5+T6+T7+T8+T9)+T3*(T4+T5+T7+T8)+T4*(T5+T6+T8+T9)+T5*(T6+T7+T8+T9)+T6*(T7+T8)+T5*(T5-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}