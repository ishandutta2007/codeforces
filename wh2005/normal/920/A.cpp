#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int T,n,k;
int a[209],c[209];
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
bool check(int x){
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++){
		int l=max(a[i]-x+1,0),r=min(a[i]+x-1,n);
		c[l]+=1,c[r+1]-=1;
	}
	for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
		if(c[i]<1) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++) scanf("%d",&a[i]);
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}