#include<bits/stdc++.h>
using namespace std;
 
const int maxn=400007;
int n,I,cnt=0,ret=-1;
int a[maxn],s[maxn];
 
int ck(){
	int ans=1;
	for (int i=1;i<=8*I/n;++i){
		ans*=2;
		if (ans>cnt) return -1;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&I);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	memset(s,0,sizeof(s));
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i){
		if (a[i]!=ret){
			ret=a[i],cnt++;
		}
		s[cnt]++;
	}
	for (int i=1;i<=cnt;++i){
		s[i]+=s[i-1];
	}
	int pI=ck();
	if (pI==-1){
		printf("%d\n",0);
		return 0;
	}
	int ans=0;
	for (int i=pI;i<=cnt;++i){
		ans=max(ans,s[i]-s[i-pI]);
	}
	printf("%d\n",n-ans);
	return 0;
}