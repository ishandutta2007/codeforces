#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
const int M=25*N;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],clock,root[N];
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]+1;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p, int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c]-x[p];
	int mid=ss+se>>1;
	return Get(ls[p],ls[c],ss,mid,qs,qe)+Get(rs[p],rs[c],mid+1,se,qs,qe);
}
vector<int> id;
int a[N];
int sol;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.push_back(a[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) a[i]=lower_bound(id.begin(),id.end(),a[i])-id.begin()+1;
	for(i=1;i<=n;i++) Set(root[i-1],root[i],1,id.size(),a[i]);
	for(i=1;i<n;i++)
	{
		sol=0;
		for(j=1;j<=n;j++)
		{
			if((j-1)*i+2>n) break;
			sol+=Get(root[(j-1)*i+1],root[min(n,(j*i+1))],1,id.size(),1,a[j]-1);
		}
		printf("%i ",sol);
	}
	printf("\n");
	return 0;
}