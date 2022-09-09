#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=2*N;
const int inf=2e9;
struct Line{
	int k,n;
	Line(){}
	Line(int a,int b):k(a),n(b){}
	int Get(int x){return k*x+n;}
};
int ls[M],rs[M],tsz,root;
Line line[M];
bool has[M];
void Set(int &c,int ss,int se,int qs,int qe,Line k){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz;
	int mid=ss+se>>1;
	if(qs<=ss && qe>=se){
		if(!has[c]){has[c]=1;line[c]=k;return;}
		int A=k.Get(ss),B=line[c].Get(ss),C=k.Get(se),D=line[c].Get(se);
		if(A<=B && C<=D){line[c]=k;return;}
		if(A>=B && C>=D)return;
		if(A<B)swap(line[c],k);
		if(line[c].Get(mid)<=k.Get(mid))Set(rs[c],mid+1,se,qs,qe,k);
		else swap(line[c],k),Set(ls[c],ss,mid,qs,qe,k);
	}else{
		Set(ls[c],ss,mid,qs,qe,k);
		Set(rs[c],mid+1,se,qs,qe,k);
	}
}
int Get(int c,int ss,int se,int qi){
	int ans=inf;
	if(has[c])ans=line[c].Get(qi);
	if(ss==se)return ans;
	int mid=ss+se>>1;
	if(qi<=mid)ans=min(ans,Get(ls[c],ss,mid,qi));
	else ans=min(ans,Get(rs[c],mid+1,se,qi));
	return ans;
}
int a[N],sum[N],l[N],r[N],ans[N];
vector<int> Qs[N];
int main(){
	int n,q;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),sum[i]=sum[i-1]+a[i];
	scanf("%i",&q);
	for(int i=1;i<=q;i++)scanf("%i %i",&l[i],&r[i]),l[i]=r[i]-l[i]+1,Qs[r[i]].pb(i);
	for(int i=1;i<=n;i++){
		Set(root,1,n,1,i,Line(-a[i],(i+1)*a[i]-sum[i]));
		for(int j:Qs[i])
			ans[j]=Get(root,1,n,l[j])+sum[r[j]];
	}
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}