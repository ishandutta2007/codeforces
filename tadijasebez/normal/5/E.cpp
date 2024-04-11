#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1000500;
const int M=2*N;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int Min[M],Max[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock,Min[c]=M;
	Min[c]=min(Min[c],qi);
	Max[c]=max(Max[c],qi);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
pair<int,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return make_pair(0,M);
	if(qs<=ss && qe>=se) return make_pair(Max[c],Min[c]);
	int mid=ss+se>>1;
	pair<int,int> u=Get(ls[c],ss,mid,qs,qe);
	pair<int,int> v=Get(rs[c],mid+1,se,qs,qe);
	return make_pair(max(u.first,v.first),min(u.second,v.second));
}
int BIT[N];
vector<int> init;
void Set(int i)
{
	for(;i<N;i+=i&-i)
	{
		if(BIT[i]==0) init.push_back(i);
		BIT[i]++;
	}
}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int Get(int i, int j){ return Get(j)-Get(i-1);}
void Init()
{
	for(int i=0;i<init.size();i++) BIT[init[i]]=0;
	init.clear();
}
int a[N];
vector< pair<int,int> > v;
bool Compare(pair<int,int> a, pair<int,int> b){ return a.first>b.first;}
ll sol,ans;
int main()
{
	Min[0]=M;
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),v.push_back(make_pair(a[i],i));
	sort(v.begin(),v.end(),Compare);
	for(i=0;i<n;i++)
	{
		j=i;
		Init();
		while(v[j].first==v[i].first)
		{
			Set(v[j].second);
			j++;
		}
		j=i;
		ans=0;
		while(v[j].first==v[i].first)
		{
			int id=v[j].second;
			pair<int,int> tmp=Get(root,1,N,1,id),tmp1=Get(root,1,N,id,n);
			if(tmp.first==0)
			{
				if(tmp1.first==0)
				{
					ans+=Get(n)-1;
				}
				else
				{
					ans+=Get(n)-Get(tmp1.second,tmp1.first)-1;
					if(tmp1.first==tmp1.second) sol++;
					else sol+=2;
				}
			}
			else
			{
				if(tmp1.first==0)
				{
					ans+=Get(n)-Get(tmp.second,tmp.first)-1;
					if(tmp.first==tmp.second) sol++;
					else sol+=2;
				}
				else
				{
					ans+=Get(n)-Get(tmp.first)-Get(tmp1.second,n)-1;
					sol+=2;
				}
			}
			j++;
		}
		sol+=ans/2;
		j=i;
		while(v[j].first==v[i].first) Set(root,1,N,v[j].second),j++;
		i=j-1;
	}
	printf("%lld\n",sol);
	return 0;
}