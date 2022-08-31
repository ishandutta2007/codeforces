#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int N=310000;
int p[N];
int pd[N],n,l,r;
int L[10],R[10];
char ch[10];
long long solve(int l,int r){
	int L[10],R[10],w[10];
	long long ans=0;
	for (int i=1;i<=2;i++){
		L[i]=1e9+10,R[i]=0; w[i]=0; int pre=p[l];
		for (int j=l+1;j<=r-1;j++)
			if (pd[j]==i){
				L[i]=min(L[i],p[j]),R[i]=max(R[i],p[j]);
				w[i]=max(w[i],p[j]-pre); pre=p[j];
			}
		w[i]=max(w[i],p[r]-pre);
	}
	long long w0=p[r]-p[l],w1=0;
	int num=0;
	for (int i=1;i<=2;i++)
		if (L[i]>R[i]) continue;
		else {
			long long t0=1e18,t1=1e18; num++;
			t0=min(t0,w0+p[r]-p[l]-w[i]);
			w0=t0;
		}

	num=max(num,2);
	w1=num*(p[r]-p[l]);
	return min(w0,w1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%s",&p[i],ch+1);
		if (ch[1]=='R') pd[i]=1;
		else if (ch[1]=='B') pd[i]=2;
		else pd[i]=3;
	}
	for (int i=1;i<=3;i++){
		L[i]=1e9+10,R[i]=0;
		for (int j=1;j<=n;j++) if (pd[j]==i) L[i]=min(L[i],p[j]),R[i]=max(R[i],p[j]);
	}
	long long ans=0;
	if (L[3]>R[3]){
		for (int i=1;i<=2;i++) ans+=max(0,R[i]-L[i]);
		cout<<ans<<endl; return 0;
	}
	int l=1,r=n;
	while (pd[l]!=3) l++;
	while (pd[r]!=3) r--;
	//cout<<l<<" "<<r<<endl;
	ans+=max(0,L[3]-L[1]);
	ans+=max(0,L[3]-L[2]);
	ans+=max(0,R[1]-R[3]);
	ans+=max(0,R[2]-R[3]);
	int pre=l;// cout<<ans<<endl;
	for (int i=l+1;i<=r;i++)
		if (pd[i]==3){
			ans+=solve(pre,i);
			pre=i;
		}
	cout<<ans<<endl; return 0;
}