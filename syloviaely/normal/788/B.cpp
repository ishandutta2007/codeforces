#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int d[1100000],pd[1100000],n,m,f[1100000];
int findfather(int k1){
	if (f[k1]==k1) return k1; return f[k1]=findfather(f[k1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	int num=0,fa=n;
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		int k3=findfather(k1),k4=findfather(k2);
		if (k3!=k4){
			num++; f[k3]=k4;
		}
		if (k1==k2){
			pd[k1]=1;
		} else d[k1]++,d[k2]++;
	}
	for (int i=1;i<=n;i++) if (d[i]==0&&pd[i]==0) fa--;
	if (num<fa-1){
		printf("0\n"); return 0;
	}
	long long ans=0,pre=0;
	for (int i=1;i<=n;i++){
		ans+=1ll*d[i]*(d[i]-1)/2;
		if (pd[i]) pre++,ans+=m-pre;
	}
	cout<<ans<<endl;
	return 0;
}