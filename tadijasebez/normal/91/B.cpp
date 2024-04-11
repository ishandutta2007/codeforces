#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
const int M=N*2;
int x[M],ls[M],rs[M],clock,root;
int max(int a, int b){ return a>b?a:b;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
vector<int> index;
int a[N],sol[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),index.push_back(a[i]);
	sort(index.begin(),index.end());
	for(i=1;i<=n;i++) a[i]=lower_bound(index.begin(),index.end(),a[i])-index.begin()+1;
	for(i=1;i<=n;i++) Set(root,1,N,a[i],i);
	for(i=1;i<=n;i++)
	{
		int tmp=Get(root,1,N,1,a[i]-1);
		if(tmp<=i) printf("-1 ");
		else printf("%i ",tmp-i-1);
	}
	printf("\n");
	return 0;
}