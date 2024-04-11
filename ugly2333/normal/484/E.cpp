//CF 484E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
int n,a[N],sl[N],sr[N];
vector<pair<int,int> > s1[N],s2[N];
int q,ql[N],qr[N],qw[N],ans[N];
vector<pair<int,int> > q1[N];
vector<pair<pair<int,int>,int> > q2[N];
int T[N<<3];
void modify(int p,int v,int k=1,int l=1,int r=n){
	if(l==r){
		T[k]=v;
		return;
	}
	int x=l+r>>1;
	if(p<=x)
		modify(p,v,k<<1,l,x);
	else
		modify(p,v,k<<1|1,x+1,r);
	T[k]=max(T[k<<1],T[k<<1|1]);
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return T[k];
	if(r<L||R<L||R<l||!T[k])
		return 0;
	int x=l+r>>1;
	return max(query(L,R,k<<1,l,x),query(L,R,k<<1|1,x+1,r));
}
pair<int,int> st[N];
int main()
{
	int i,j,x,y,z,sz,nn;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	a[0]=0,a[n+1]=0;
	sz=0;
	st[++sz]=make_pair(0,0);
	for(i=1;i<=n+1;i=i+1){
		while(st[sz].first>a[i]){
			sr[st[sz--].second]=i-1;
		}
		st[++sz]=make_pair(a[i],i);
	}
	sz=1;
	for(i=n;i>=0;i=i-1){
		while(st[sz].first>a[i]){
			sl[st[sz--].second]=i+1;
		}
		st[++sz]=make_pair(a[i],i);
	}
	for(i=1;i<=n;i=i+1){
		x=sl[i],y=sr[i],z=a[i];
		//cout<<x<<y<<z<<endl;
		s1[x].push_back(make_pair(y,z));
		s2[y-x].push_back(make_pair(y+x,z));
	}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d%d",ql+i,qr+i,qw+i);
		x=ql[i],y=qr[i],z=qw[i];
		q1[x].push_back(make_pair(x+z-1,i));
		q1[y-z+1].push_back(make_pair(y,i));
		q2[z-1].push_back(make_pair(make_pair(x+x+z-1,y-z+1+y),i));
	}
	memset(T,0,sizeof(T));
	for(i=1;i<=n;i=i+1){
		sz=s1[i].size();
		for(j=0;j<sz;j=j+1)
			modify(s1[i][j].first,s1[i][j].second);
		sz=q1[i].size();
		for(j=0;j<sz;j=j+1)
			ans[q1[i][j].second]=max(ans[q1[i][j].second],query(q1[i][j].first,n));
	}
	memset(T,0,sizeof(T));
	n=n+n;
	for(i=n/2;i>=0;i=i-1){
		sz=s2[i].size();
		for(j=0;j<sz;j=j+1)
			modify(s2[i][j].first,s2[i][j].second);
		sz=q2[i].size();
		for(j=0;j<sz;j=j+1)
			ans[q2[i][j].second]=max(ans[q2[i][j].second],query(q2[i][j].first.first,q2[i][j].first.second));
	}
	for(i=1;i<=q;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}