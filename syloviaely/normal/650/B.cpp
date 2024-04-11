#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int w[510000],n,a,b,T,A[510000];
char ch[510000];
int get(){
	int r=1; A[0]=0; int ans=0;
	for (int i=1;i<=n;i++) A[i]=A[i-1]+w[i];
	for (int l=1;l<=n;l++){
		r=max(r,l+1);
		while (r<=n){
			long long w=A[l]+A[n]-A[r-1]+1ll*(l-1+l-1+n-r+1)*a;
			if (w>T) r++; else break;
		}
		if (A[l]+A[n]-A[r-1]+1ll*(l-1+l-1+n-r+1)*a<=T) ans=max(ans,l+n-r+1);
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&T);
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++)
		if (ch[i]=='w') w[i]=1+b; else w[i]=1;
	int ans=get();
	for (int i=1;i<=n;i++) if (1+i<=n-i+1) swap(w[i+1],w[n-i+1]);
	ans=max(ans,get());
	cout<<ans<<endl;
	return 0;
}