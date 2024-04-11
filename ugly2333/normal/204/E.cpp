//CF 204E
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
vector<char> s[111111];
char c[111111],cc[222222];
int l[111111],rk[222222],h[222222],f[111111],ql[222222],qr[222222],q[222222];
LL ans[111111];
pair<int,int> sa[222222];
pair<pair<int,int>,int> a[222222];
int T[222222],T2[222222];
void build(int x,int l,int r)
{
	if(l>r)
		return;
	if(l==r){
		T[x]=h[l];
		return;
	}
	int md;
	md=(l+r)/2;
	build(x*2,l,md);
	build(x*2+1,md+1,r);
	T[x]=min(T[x*2],T[x*2+1]);
}
int query(int x,int ll,int rr,int l,int r)
{
	if(ll>r||rr<l||l>r)
		return 1<<30;
	if(ll==l&&rr==r)
		return T[x];
	int md;
	md=(ll+rr)/2;
	return min(query(x*2,ll,md,l,min(md,r)),query(x*2+1,md+1,rr,max(md+1,l),r));
}
void build2(int x,int l,int r)
{
	if(l>r)
		return;
	if(l==r){
		T2[x]=q[l];
		return;
	}
	int md;
	md=(l+r)/2;
	build2(x*2,l,md);
	build2(x*2+1,md+1,r);
	T2[x]=max(T2[x*2],T2[x*2+1]);
}
int query2(int x,int ll,int rr,int l,int r)
{
	if(ll>r||rr<l||l>r)
		return 0;
	if(ll==l&&rr==r)
		return T2[x];
	int md;
	md=(ll+rr)/2;
	return max(query2(x*2,ll,md,l,min(md,r)),query2(x*2+1,md+1,rr,max(md+1,l),r));
}
int main()
{
	int n,k,sn,i,j,x,x1,y1,x2,y2,m,ss;
	cin>>n>>k;
	sn=0;
	for(i=1;i<=n;i=i+1){
		scanf("%s",&c);
		l[i]=strlen(c);
		for(j=0;j<l[i];j=j+1){
			s[i].push_back(c[j]);
			sn++;
			cc[sn]=c[j];
			rk[sn]=c[j]-'a'+1;
		}
		sn++;
		cc[sn]='a'-1;
		rk[sn]=0;
	}
	for(x=1;x<=sn;x*=2)
	{
		for(i=1;i<=sn;i=i+1){
			a[i].first.first=rk[i];
			if(i+x<=sn)
				a[i].first.second=rk[i+x];
			else
				a[i].first.second=0;
			a[i].second=i;
		}
		sort(a+1,a+sn+1);
		j=0;
		for(i=1;i<=sn;i=i+1){
			if(a[i].first==a[i-1].first)
				rk[a[i].second]=j;
			else
				rk[a[i].second]=j+1;
			j=rk[a[i].second];
		}
	}
	for(i=1;i<=sn;i=i+1)
		rk[i]++;
	for(i=1;i<=sn;i=i+1)
		sa[rk[i]]=make_pair(i,0);
	x=0;
	h[0]=0;
	for(i=1;i<=sn;i=i+1){
		j=sa[rk[i]-1].first;
		if(x>0)
			x--;
		for(;cc[i+x]!=96&&i+x<=sn&&j+x<=sn;x++){
			if(cc[i+x]!=cc[j+x])
				break;
		}
		h[rk[i]-1]=x;
	}
	m=0;
	for(i=1;i<=n;i=i+1){
		for(j=0;j<=l[i];j=j+1){
			m++;
			sa[rk[m]]=make_pair(i,j);
		}
	}
	for(i=n+1;i<=sn;i=i+1){
		sa[i-n]=sa[i];
		h[i-n]=h[i];
	}
	/*for(i=1;i<=sn;i=i+1){
		cout<<i<<' '<<h[i]<<' '<<rk[i]<<' '<<sa[i].first<<' ';
		for(j=sa[i].second;j<l[sa[i].first];j=j+1)
			cout<<s[sa[i].first][j];
		cout<<endl;
	}*/
	m=sn-n;
	build(1,1,m-1);
	for(i=0;i<=n+1;i=i+1)
		f[i]=0;
	i=1;
	j=0;
	ss=0;
	x=0;
	while(j<=m&&ss<k){
		j++;
		if(f[sa[j].first]==0)
			ss++;
		f[sa[j].first]++;
	}
	while(j<=m){
		x++;
		ql[x]=i;
		qr[x]=j;
		q[x]=query(1,1,m-1,i,j-1);
		//cout<<i<<' '<<j<<endl;
		if(ss>k||f[sa[i].first]!=1){
			f[sa[i].first]--;
			if(f[sa[i].first]==0)
				ss--;
			i++;
		}
		else{
			j++;
			if(j>m)
				break;
			if(f[sa[j].first]==0)
				ss++;
			f[sa[j].first]++;
		}
	}
	build2(1,1,x);
	for(i=1;i<=m;i=i+1)
	{
		x1=upper_bound(ql+1,ql+x+1,i)-ql;
		x2=lower_bound(qr+1,qr+x+1,i)-qr;
		ans[sa[i].first]+=(LL)query2(1,1,x,x2,x1-1);
	}
	if(k==1){
		for(i=1;i<=n;i=i+1)
			ans[i]=(LL)1*l[i]*(l[i]+1);
		for(i=1;i<=n;i=i+1)
			ans[i]/=(LL)2;
	}
	for(i=1;i<=n;i=i+1)
		printf("%I64d ",ans[i]);
	return 0;
}
/*
11 47
bwxotc
vb
cwrdb
k
b
paqveqyhr
fbummcgk
ftax
lzcheeccnk
njjnh
iveqsqfdpavepezdoztsvez
7 4
rubik
furik
abab
baba
aaabbbababa
abababababa
zero

*/