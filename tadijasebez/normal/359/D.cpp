#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int x, int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
const int N=300050;
int A[N],Table[N][20],logs[N];
void Preprocess()
{
	int k=0,i;
	for(i=0;i<N;i++)
	{
		if(i==1<<(k+1)) k++;
		logs[i]=k;
	}
}
void BuildSparseTable(int n)
{
	int i,j;
	Preprocess();
	for(i=1;i<=n;i++) Table[i][0]=A[i];
	for(j=1;j<20;j++)
		for(i=1;i<=n-(1<<j)+1;i++)
			Table[i][j]=gcd(Table[i][j-1],Table[i+(1<<(j-1))][j-1]);
}
int Query(int l, int r)
{
	int k=logs[r-l+1];
	return gcd(Table[l][k],Table[r-(1<<k)+1][k]);
}
const int M=2*N;
const int inf=1e9;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock,x[c]=val;
	x[c]=min(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int sol;
vector<int> ans;
int main()
{
	x[0]=inf;
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&A[i]);
		//Set(root,1,n,i,A[i]);
	}
	BuildSparseTable(n);
	int top,bot,mid,sol1,sol2;
	for(i=1;i<=n;i++)
	{
		top=n;
		bot=i;
		sol1=i;
		while(top>=bot)
		{
			mid=top+bot>>1;
			//int a=Get(root,1,n,i,mid);
			int b=Query(i,mid);
			if(b==A[i]) sol1=mid,bot=mid+1;
			else top=mid-1;
		}
		top=i;
		bot=1;
		sol2=i;
		while(top>=bot)
		{
			mid=top+bot>>1;
			//int a=Get(root,1,n,mid,i);
			int b=Query(mid,i);
			if(b==A[i]) sol2=mid,top=mid-1;
			else bot=mid+1;
		}
		if(sol1-sol2>sol)
		{
			sol=sol1-sol2;
			ans.clear();
		}
		if(sol1-sol2==sol) ans.push_back(sol2);
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	//if(ans[1]==27533) printf("%i %i %i %i %i\n",A[21842],A[21843],A[21844],A[21845],A[21846]);
	printf("%i %i\n",ans.size(),sol);
	for(i=0;i<ans.size();i++) printf("%i ",ans[i]);
	printf("\n");
	return 0;
}