//CF1726G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<20;
const int MO = 998244353;
const int inf = 1e9;
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,m,a[N],b[N],t[N],el[N];
pair<int,int> p[N];
void ad(int x,int y){
	while(x<N){
		t[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
int f[N],w[N];
void modify(int L,int R,int X,int k=1,int l=1,int r=m){
	if(L<=l&&r<=R){
		w[k]+=X;
		f[k]+=X;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,X,k<<1,l,h);
	if(h<R)
		modify(L,R,X,k<<1|1,h+1,r);
	f[k]=max(f[k<<1],f[k<<1|1])+w[k];
}
int query(int t,int k=1,int l=1,int r=m){
	if(l==r)
		return l;
	int h=l+r>>1;
	t-=w[k];
	if(f[k<<1|1]==t)
		return query(t,k<<1|1,h+1,r);
	return query(t,k<<1,l,h);
}
int main()
{
	int i,j,x,y,z,t,s,c1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",b+i),p[i]=make_pair(a[i],b[i]);
	sort(p+1,p+n+1);
	if(p[1].second==0||p[1].first==p[n].first){
		if(p[n].first!=p[1].first)
			printf("0");
		else{
			x=1;
			for(i=1;i<=n;i++)
				x=mul(x,i);
			printf("%d",x);
		}
		return 0;
	}
	t=p[1].first+n-1;
	if(p[n].first>t){
		printf("0");
		return 0;
	}
	i=n;
	s=1;
	while(p[i]==make_pair(t,1)){
		s=mul(s,i);
		i--;
	}
	m=i;
	for(i=1;i<=m;i++)
		ad(p[i].first,1);
	c1=0;
	for(i=1;i<=m;i++){
		if(p[i].second==1)
			modify(i,i,p[i].first+n-qu(p[i].first)),c1++;
		else
			modify(i,i,-inf);
	}
	for(i=1;i<=m;i++){
		if(p[i].first==p[i-1].first)
			el[i]=el[i-1];
		else
			el[i]=i;
	}
	i=1;
	while(1){
		while(i<=m&&p[i].second==1)i++;
		if(i>m&&!c1)
			break;
		if(f[1]>t){
			printf("0");
			return 0;
		}
		if(!c1||f[1]<t)
			j=0;
		else
			j=query(t);
		x=i<=m&&p[i].first+qu(p[i].first-1)==t;
		y=j>=1;
		if(!x&&!y){
			printf("0");
			return 0;
		}
		if(x&&y){
			if(p[i].first<=p[j].first)
				x=0,y=1;
			else
				x=1,y=0;
		}
		if(x)
			j=i,i++;
		ad(p[j].first,-1);
		modify(el[j],m,1);
		if(y)
			modify(j,j,-inf),c1--;
	}
	for(i=1;i<=m;i++){
		if(i==1||p[i]!=p[i-1])
			x=1;
		else
			x++;
		s=mul(s,x);
	}
	printf("%d\n",s);
	return 0;
}