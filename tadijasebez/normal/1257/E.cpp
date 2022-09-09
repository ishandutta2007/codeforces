#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,root,lzy[M],mn[M];
void Add(int &c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz;
	if(qs<=ss && qe>=se){lzy[c]+=f;mn[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss && qe>=se)return mn[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe)+lzy[c];
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe)+lzy[c];
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
int a[N];
int main(){
	int n,k1,k2,k3,x;
	scanf("%i %i %i",&k1,&k2,&k3);
	n=k1+k2+k3;
	while(k1--)scanf("%i",&x),a[x]=1;
	while(k2--)scanf("%i",&x),a[x]=2;
	while(k3--)scanf("%i",&x),a[x]=3;
	function<void(int,int,int)> Add=[&](int l,int r,int f){::Add(root,1,n+1,l,r,f);};
	function<int(int,int)> Get=[&](int l,int r){return ::Get(root,1,n+1,l,r);};
	int bal=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1)bal++;
		else if(a[i]==2)Add(1,i,1);
		else if(a[i]==3)Add(i+1,n+1,1);
	}
	int ans=bal+Get(1,n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==1)bal--;
		else if(a[i]==2)Add(1,i,-1),bal++;
		else if(a[i]==3)Add(i+1,n+1,-1),bal++;
		ans=min(ans,bal+Get(i+1,n+1));
	}
	printf("%i\n",ans);
	return 0;
}