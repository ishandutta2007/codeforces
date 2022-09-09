#include <stdio.h>
#include <vector>
using namespace std;
const int N=1000050;
const int M=2*N;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	//printf("%i %i %i\n",c,ss,se);
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int k)
{
	if(ss==se) return ss;
	int mid=ss+se>>1;
	if(x[ls[c]]<k) return Get(rs[c],mid+1,se,k-x[ls[c]]);
	else return Get(ls[c],ss,mid,k);
}
int a[N],b[N];
bool mark[N];
vector<int> bad;
int main()
{
	int n,q,i,m=0,x;
	scanf("%i %i",&q,&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	while(q--)
	{
		scanf("%i",&x);
		if(x==-1)
		{
			bad.clear();
			//printf(" ");
			for(i=1;i<=n;i++)
			{
				x=Get(root,1,N,a[i]);
				//printf("%i ",x);
				if(x>m) break;
				bad.push_back(x);
			}
			//printf("\n");
			for(i=0;i<bad.size();i++) mark[bad[i]]=1,Set(root,1,N,bad[i],-1);
		}
		else
		{
			b[++m]=x;
			Set(root,1,N,m,1);
		}
	}
	bool ok=0;
	for(i=1;i<=m;i++) if(!mark[i]) printf("%i",b[i]),ok=1;
	if(!ok) printf("Poor stack!\n");
	return 0;
}