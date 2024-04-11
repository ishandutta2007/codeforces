#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
const int mod=1e9+7;
int a[maxn],b[maxn],p[maxn],q[maxn],vol[maxn],val[maxn];
bool comp1(int i,int j){
	return a[i]<a[j];
}

bool comp2(int i,int j){
	return b[i]<b[j];
}

int main(){
	int n;
	scanf("%d",&n);
	int mxb=0;
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);
		p[i]=q[i]=i;
		mxb=max(mxb,b[i]);
	}
	sort(p+1,p+n+1,comp1);
	sort(q+1,q+n+1,comp2);
	int j=0,mx=0,ans=1;
	for (int i=1;i<=n;++i){
		while (a[p[j+1]]<=b[q[i]]){
			j++;
			if (vol[p[j]]>mx){
				mx=vol[p[j]];
				ans=0;
			}
			if (vol[p[j]]==mx){
				ans=(ans+val[p[j]])%mod;
			} 
		}
		vol[q[i]]=mx+a[q[i]]-b[q[i]];
		val[q[i]]=ans;
	}
	int mn=0x7fffffff,ret=0;
	for (int i=1;i<=n;++i){
		if (a[i]<=mxb) continue;
		if (a[i]-vol[i]<mn){
			mn=a[i]-vol[i];
			ret=0;
		} 
		if (a[i]-vol[i]==mn){
			ret=(ret+val[i])%mod;
		}
	}
	printf("%d\n",ret);
	return 0;
}