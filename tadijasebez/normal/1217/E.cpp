#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int L=10;
const int M=N*4;
const int inf=1e9+7;
int fir[L][M],sec[L][M],n;
void Build(int d,int c,int ss,int se){
	fir[d][c]=sec[d][c]=inf;
	if(ss==se)return;
	int mid=ss+se>>1;
	Build(d,c<<1,ss,mid);
	Build(d,c<<1|1,mid+1,se);
}
void pull(int d,int c){
	if(fir[d][c<<1]<fir[d][c<<1|1])
		fir[d][c]=fir[d][c<<1],
		sec[d][c]=min(sec[d][c<<1],fir[d][c<<1|1]);
	else
		fir[d][c]=fir[d][c<<1|1],
		sec[d][c]=min(fir[d][c<<1],sec[d][c<<1|1]);
}
void Set(int d,int c,int ss,int se,int qi,int x){
	if(ss==se){fir[d][c]=x;sec[d][c]=inf;return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(d,c<<1,ss,mid,qi,x);
	else Set(d,c<<1|1,mid+1,se,qi,x);
	pull(d,c);
}
pair<int,int> mrg(pair<int,int> a,pair<int,int> b){
	if(a.first>b.first)swap(a,b);
	return {a.first,min(a.second,b.first)};
}
pair<int,int> Get(int d,int c,int ss,int se,int qs,int qe){
	if(qs<=ss && qe>=se)return {fir[d][c],sec[d][c]};
	int mid=ss+se>>1;
	if(qe<=mid)return Get(d,c<<1,ss,mid,qs,qe);
	if(qs>mid)return Get(d,c<<1|1,mid+1,se,qs,qe);
	return mrg(Get(d,c<<1,ss,mid,qs,qe),Get(d,c<<1|1,mid+1,se,qs,qe));
}
void Add(int qi,int x){
	int y=x;
	for(int i=0;i<L;i++){
		if(x%10!=0)Set(i,1,1,n,qi,y);
		else Set(i,1,1,n,qi,inf);
		x/=10;
	}
}
int a[N];
int main(){
	int q;
	scanf("%i %i",&n,&q);
	for(int i=0;i<L;i++)Build(i,1,1,n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),Add(i,a[i]);
	while(q--){
		int t,l,r;
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)Add(l,r);
		else{
			int ans=inf*2;
			for(int i=0;i<L;i++){
				pair<int,int> A=Get(i,1,1,n,l,r);
				if(A.second!=inf)ans=min(ans,A.first+A.second);
				//printf("(%i %i)\n",A.first,A.second);
			}
			if(ans==inf*2)printf("-1\n");
			else printf("%i\n",ans);
		}
	}
	return 0;
}