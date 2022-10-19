#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,q;
int cnt[N];
bitset<N>w[N],z[N];
void reverse(int x,int l,int r)
{
	w[x]^=z[r-l+1]<<l;
	cnt[x]=w[x].count();
}
struct cmp{bool operator()(const int x,const int y)const{return(cnt[x]!=cnt[y])?cnt[x]<cnt[y]:x<y;}};
set<int,cmp>s;
vector<int>inv;
void report(int x1,int x2)
{
	bitset<N> B=w[x1]^w[x2],B1=B&w[x1],B2=B&w[x2];
	int y1=B1._Find_first(),y2=B2._Find_first();
	if(x1>x2){int t=x1;x1=x2,x2=t;}
	if(y1>y2){int t=y1;y1=y2,y2=t;}
	printf("%d %d %d %d\n",x1,y1,x2,y2); 
}
void tryIns()
{
	while(inv.size())
	{
		int T=inv.back();
		int pre=*--s.lower_bound(T),nxt=*s.upper_bound(T);
		if(pre)
			if((w[T]&w[pre])!=w[pre])
				return report(pre,T);
		if(nxt!=n+1)
			if((w[T]&w[nxt])!=w[T])
				return report(T,nxt);
		s.insert(T),inv.pop_back();
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	cnt[0]=-1e9,cnt[n+1]=1e9;
	for(int i=0;i<=n+1;i++)
		s.insert(i);
	for(int i=1;i<=m;i++)
		z[i]=z[i-1],z[i][i-1]=1;
	for(int i=1;i<=q;i++)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		if(s.find(x)!=s.end())
			s.erase(x),inv.push_back(x);
		reverse(x,l,r),tryIns();
		if(!inv.size())
			puts("-1");
	}
	return 0;
}