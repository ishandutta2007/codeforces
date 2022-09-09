#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
const int M=4*N*20;
const int inf=1e9+7;
int ls[M],rs[M],tsz,rtl[N],rtr[N],mx[M];
void Set(int p,int &c,int ss,int se,int qi,int x){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];mx[c]=max(x,mx[p]);
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi,x);
	else Set(rs[p],rs[c],mid+1,se,qi,x);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return mx[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
vector<int> all;
int GetL(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
int GetR(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
int a[N],b[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),a[i]-=i,b[i]=a[i],all.pb(a[i]);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1;
	int lim=all.size();
	for(int i=1;i<=n;i++)Set(rtl[i-1],rtl[i],1,lim,a[i],Get(rtl[i-1],1,lim,1,a[i])+1);
	for(int i=n;i>=1;i--)Set(rtr[i+1],rtr[i],1,lim,a[i],Get(rtr[i+1],1,lim,a[i],lim)+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i<n)ans=max(ans,Get(rtl[i],1,lim,a[i],a[i])+Get(rtr[i+2],1,lim,GetL(b[i]-1),lim));
		if(i>1)ans=max(ans,Get(rtr[i],1,lim,a[i],a[i])+Get(rtl[i-2],1,lim,1,GetR(b[i]+1)));
	}
	printf("%i\n",n-ans-1);
	return 0;
}