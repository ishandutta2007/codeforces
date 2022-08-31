#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[6000],n,m,x[6000],y[11000],where[10000],w[6000];
int lift(int k){
	int k1=where[k],ans=0;
	for (int i=k1-1;i;i--){
		A[i+1]=A[i]; where[A[i+1]]=i+1; ans+=x[A[i]];
	}
	A[1]=k; where[k]=1; return ans;
}
int compare(int k1,int k2){
	return w[k1]<w[k2];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=m;i++) scanf("%d",&y[i]);
	for (int i=1;i<=n;i++) w[i]=m+1;
	for (int i=1;i<=m;i++) if (w[y[i]]==m+1) w[y[i]]=i;
	for (int i=1;i<=n;i++) A[i]=i;
	sort(A+1,A+n+1,compare);
	for (int i=1;i<=n;i++) where[A[i]]=i; int ans=0;
	for (int i=1;i<=m;i++) ans+=lift(y[i]);
	cout<<ans<<endl; return 0;
}