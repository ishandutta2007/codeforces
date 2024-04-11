#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=500050;
const int M=N*2;
vector<int> id;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi, int X)
{
	if(!c) c=++clock;
	x[c]=max(x[c],X);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,X);
	else Set(rs[c],mid+1,se,qi,X);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int a[N],b[N],c[N],d[N],sol;
bool comp(int u, int v){ return a[u]>a[v];}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<=n;i++) d[i]=i;
	for(i=1;i<=n;i++) id.push_back(b[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	sort(d+1,d+1+n,comp);
	for(i=1;i<=n;i++)
	{
		for(j=i;a[d[i]]==a[d[j]] && j<=n;j++)
		{
			int k=lower_bound(id.begin(),id.end(),b[d[j]])-id.begin()+1;
			if(c[d[j]]<Get(root,1,id.size(),k+1,id.size())) sol++;
		}
		for(j=i;a[d[i]]==a[d[j]] && j<=n;j++)
		{
			int k=lower_bound(id.begin(),id.end(),b[d[j]])-id.begin()+1;
			Set(root,1,id.size(),k,c[d[j]]);
		}
		i=j-1;
	}
	printf("%i\n",sol);
	return 0;
}