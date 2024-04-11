//CF 811E
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
struct Tree{
	int x;
	int l;
	int r;
	int cl[11];
	int cr[11];
}T[888888];
int n,a[111111][11],ff;
pair<int,int> f[111];
int d[44];
int fnd(int k)
{
	if(d[k]==k)
		return k;
	d[k]=fnd(d[k]);
	return d[k];
}
void merg(int k,int le,int ri,int md)
{
	int i,j;
	T[k].x=T[le].x+T[ri].x;
	for(i=0;i<44;i=i+1){
		d[i]=i;
	}
	for(i=1;i<=n;i=i+1){
		if(a[md][i]==a[md+1][i]&&fnd(T[le].cr[i])!=fnd(T[ri].cl[i]+22)){
			T[k].x--;
			d[fnd(T[ri].cl[i]+22)]=fnd(T[le].cr[i]);
		}
	}
	for(i=1;i<=n;i=i+1){
		T[k].cl[i]=fnd(T[le].cl[i]);
		T[k].cr[i]=fnd(T[ri].cr[i]+22);
	}
	for(i=0;i<44;i=i+1)
		d[i]=0;
	j=0;
	for(i=1;i<=n;i=i+1){
		if(d[T[k].cl[i]]==0){
			j++;
			d[T[k].cl[i]]=j;
		}
		T[k].cl[i]=d[T[k].cl[i]];
		if(d[T[k].cr[i]]==0){
			j++;
			d[T[k].cr[i]]=j;
		}
		T[k].cr[i]=d[T[k].cr[i]];
	}
}
void build(int k,int ll,int rr)
{
	T[k].l=ll;
	T[k].r=rr;
	if(ll==rr){
		int i,s;
		s=0;
		T[k].cl[0]=0;
		for(i=1;i<=n;i=i+1){
			if(a[ll][i]==a[ll][i-1])
				T[k].cl[i]=T[k].cl[i-1];
			else{
				T[k].cl[i]=T[k].cl[i-1]+1;
				s++;
			}
			T[k].cr[i]=T[k].cl[i];
		}
		T[k].x=s;
		return;
	}
	int md;
	md=(ll+rr)/2;
	build(k*2,ll,md);
	build(k*2+1,md+1,rr);
	merg(k,k*2,k*2+1,md);
}
void query(int k,int ll,int rr)
{
	//cout<<k<<ll<<rr<<endl;
	if(ll>rr||T[k].l>rr||T[k].r<ll)
		return;
	if(T[k].l==ll&&T[k].r==rr){
		ff++;
		f[ff]=make_pair(T[k].l,k);
		return;
	}
	int md;
	md=(T[k].l+T[k].r)/2;
	if(ll<=md)
		query(k*2,ll,min(md,rr));
	if(md+1<=rr)
		query(k*2+1,max(ll,md+1),rr);
}
void print(int i)
{
	int j;
	printf("%d %d %d %d\n",i,T[i].l,T[i].r,T[i].x);
	for(j=1;j<=n;j=j+1)
		printf("%d ",T[i].cl[j]);
	printf("\n");
	for(j=1;j<=n;j=j+1)
		printf("%d ",T[i].cr[j]);
	printf("\n\n");
}
int main()
{
	int m,q,i,j,ql,qr,p;
	cin>>n>>m>>q;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1)
			scanf("%d",&a[j][i]);
	}
	build(1,1,m);
	//for(i=1;i<2*m;i=i+1)
	//	print(i);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",&ql,&qr);
		ff=0;
		query(1,ql,qr);
		sort(f+1,f+ff+1);
		p=800000;
		T[p+1]=T[f[1].second];
		//for(j=1;j<=ff;j++)
		//	cout<<f[j].first<<' '<<f[j].second<<endl;
		for(j=2;j<=ff;j=j+1){
			merg(p+j,p+j-1,f[j].second,f[j].first-1);
		}
		cout<<T[p+ff].x<<endl;
		for(j=0;j<=ff;j=j+1)
			f[j]=make_pair(0,0);
	}
	return 0;
}
/*
9 9 3
2 1 2 1 2 1 1 1 1
1 1 1 1 1 1 1 2 2
2 2 2 2 1 1 1 1 1
2 2 2 2 1 1 1 2 2
2 2 2 1 1 1 2 2 2
2 1 1 1 2 2 2 1 2
1 2 2 2 2 2 1 1 1
1 2 2 1 2 1 2 1 2
1 2 1 1 1 1 1 1 1
1 9
2 8
3 5
*/