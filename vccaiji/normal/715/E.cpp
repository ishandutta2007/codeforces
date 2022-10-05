#include<bits/stdc++.h>
using namespace std;
const int ppp=998244353;
int fa[300];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool ap[300]={};
bool cy[300]={};
int p[300];
int q[300];
int num[300];
int ans[300]={};
int main(){
	int n,tot1=0,tot2=0,n1=0,n2=0,n3=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if((p[i]>0)&&(q[i]>0)){
			int pp=find(p[i]);
			int qq=find(q[i]);
			if(pp==qq) cy[pp]=true;
			else fa[pp]=qq;	
		}
	}
	for(int i=1;i<=n;i++){
		if(cy[i]) tot2++;
		if((fa[i]==i)&&(!cy[i])) tot1++;
	}
	for(int i=1;i<=n;i++){
		if((p[i]>0)&&(q[i]==0)){
			ap[find(p[i])]=true;
			n1++;
		} 
	}
	for(int i=1;i<=n;i++){
		if((p[i]==0)&&(q[i]>0)){
			if(ap[find(q[i])]){
				n3++;
				n1--;
			}
			else n2++;
		}
		if((p[i]==0)&&(q[i]==0)) n3++;
	}
    //cout<<n1<<n2<<n3<<tot2;
	ans[0]=1;
	for(int i=0;i<n3;i++){
		for(int j=i+1;j>=1;j--) ans[j]=(1ll*i*ans[j]+ans[j-1])%ppp;
		ans[0]=(1ll*i*ans[0])%ppp;
		for(int j=0;j<=i+1;j++) ans[j]=(1ll*(i+1)*ans[j])%ppp;
	}
	for(int i=n3;i<n1+n3;i++){
		for(int j=i+1;j>=1;j--) ans[j]=(1ll*i*ans[j]+ans[j-1])%ppp;
		ans[0]=(1ll*i*ans[0])%ppp;
	}
	for(int i=n3;i<n2+n3;i++){
		for(int j=i+n1+1;j>=1;j--) ans[j]=(1ll*i*ans[j]+ans[j-1])%ppp;
		ans[0]=(1ll*i*ans[0])%ppp;
	}
	for(int i=0;i<=n-1;i++){
		if(i<=n-tot2) printf("%d ",ans[n-tot2-i]); 
		else printf("0 ");
	}
	return 0;
}