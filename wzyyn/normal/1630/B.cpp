#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,k;
int a[N],q[N],loc[N];
void solve(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),q[i]=a[i];
	sort(q+1,q+n+1);
	int vl,vr,v=1ll<<30,l=1;
	for (;2*l-n<k;++l);
	for (int i=l;i<=n;i++)
		if (q[i]-q[i-l+1]<v){
			v=q[i]-q[i-l+1];
			vl=q[i-l+1]; vr=q[i];
		}
	printf("%d %d\n",vl,vr);
	int s=0;
	for (int i=1;i<=n;i++){
		if (vl<=a[i]&&a[i]<=vr) ++s;
		else --s;
		if (s>=0) loc[s]=i;
	}
	int la=1;
	for (int i=1;i<k;i++){
		printf("%d %d\n",la,loc[i]);	
		la=loc[i]+1;
	}
	printf("%d %d\n",la,n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
0 i j (2^n-1)

*/