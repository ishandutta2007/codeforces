#include<bits/stdc++.h>
using namespace std;
int n,cnt_OneEdge,cnt_ManyEdges;
inline bool OneEdge(int a,int b)
{
	assert(a>=0&&a<=n-1);
	assert(b>=0&&b<=n-1);
	assert(a!=b);
	assert(++cnt_OneEdge<=9*n);
	printf("1 %d %d\n",a,b);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	assert(res!=-1);
	return res;
}
inline bool ManyEdges(int x,vector<int> s)
{
	int k=(int)s.size();
	assert(x>=0&&x<=n-1);
	assert(k>=0&&k<n);
	for(int i=0;i<k;++i)
	{
		assert(s[i]>=0&&s[i]<=n-1);
		assert(x!=s[i]);
		for(int j=0;j<i;++j)
			assert(s[i]!=s[j]);
	}
	assert(++cnt_ManyEdges<=2*n);
	printf("2 %d %d%c",x,k,k?' ':'\n');
	for(int i=0;i<k;++i)
		printf("%d%c",s[i],i+1<k?' ':'\n');
	fflush(stdout);
	int res;
	scanf("%d",&res);
	assert(res!=-1);
	return res;
}
void MergeSort(vector<int> &v,int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	MergeSort(v,l,mid);
	MergeSort(v,mid+1,r);
	vector<int> now;
	for(int i=l,j=mid+1;i<=mid||j<=r;)
	{
		if(i<=mid&&(j>r||OneEdge(v[i],v[j])))
			now.push_back(v[i++]);
		else
			now.push_back(v[j++]);
	}
	for(int i=l;i<=r;++i)
		v[i]=now[i-l];
}
inline vector<int> get_prefix(const vector<int> &v,int len)
{
	assert((int)v.size()>=len);
	vector<int> res;
	for(int i=0;i<len;++i)
		res.push_back(v[i]);
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int id=1;id<=t;++id)
	{
		cnt_OneEdge=cnt_ManyEdges=0;
		scanf("%d",&n);
		vector<int> Hamiltonian_path(n);
		for(int i=0;i<n;++i)
			Hamiltonian_path[i]=i;
		MergeSort(Hamiltonian_path,0,n-1);
//		fprintf(stderr,"Hamiltonian path: ");
//		for(int i=0;i<n;++i)
//			fprintf(stderr,"%d%c",Hamiltonian_path[i],i+1<n?' ':'\n');
		vector<vector<bool> > Map(n,vector<bool>(n,true));
		for(int i=n-1,p=n-1;i>=0;--i)
		{
			p=min(p,i);
			while(p>0&&ManyEdges(Hamiltonian_path[i],get_prefix(Hamiltonian_path,p)))
				--p;
			if(p==i)
			{
				for(int j=0;j<=i-1;++j)
					for(int k=i;k<=n-1;++k)
						Map[Hamiltonian_path[k]][Hamiltonian_path[j]]=false;
			}
		}
		for(int i=0;i<n;++i)
			assert(Map[i][i]);
		puts("3");
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				putchar(Map[i][j]+'0');
			putchar('\n');
		}
		fflush(stdout);
		int res;
		scanf("%d",&res);
		if(res==-1)
		{
//			fprintf(stderr,"Wrong answer on test case %d\n",id);
			return 0;
		}
//		fprintf(stderr,"Test case %d solved.\n",id);
	}
	return 0;
}