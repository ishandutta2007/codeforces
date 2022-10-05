#include<bits/stdc++.h>//luogu
using namespace std;
int n,q,p;
int a[310000];
int b[310000];
int f[310000];
int main(){
	scanf("%d%d%d",&n,&q,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) a[i]=(a[i]+p-b[i])%p;
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=n+2;i++) f[i]=(f[i-1]+f[i-2])%p;
	int num=0;
	for(int i=n;i>=1;i--){
		if(i>1) a[i]=(a[i]+p-a[i-1])%p;
		if(i>2) a[i]=(a[i]+p-a[i-2])%p;
	}
	for(int i=1;i<=n;i++) if(a[i]) num++;
	for(int i=1;i<=q;i++){
		char t[3];
		int l,r;
		scanf("%s%d%d",t,&l,&r);
		if(t[0]=='A'){
			if(a[l]==0) num++; 
			a[l]=(a[l]+1)%p;
			if(a[l]==0) num--;
			if(r+1<=n){
				if(a[r+1]==0) num++;
				a[r+1]=(a[r+1]-f[r-l+2]+p)%p;
				if(a[r+1]==0) num--;
			}
			if(r+2<=n){
				if(a[r+2]==0) num++;
				a[r+2]=(a[r+2]-f[r-l+1]+p)%p;
				if(a[r+2]==0) num--;
			}
		}
		else{
			if(a[l]==0) num++; 
			a[l]=(a[l]-1)%p;
			if(a[l]==0) num--;
			if(r+1<=n){
				if(a[r+1]==0) num++;
				a[r+1]=(a[r+1]+f[r-l+2])%p;
				if(a[r+1]==0) num--;
			}
			if(r+2<=n){
				if(a[r+2]==0) num++;
				a[r+2]=(a[r+2]+f[r-l+1])%p;
				if(a[r+2]==0) num--;
			}
		}
		if(num==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}