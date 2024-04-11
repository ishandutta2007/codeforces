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
#include <queue>
using namespace std;
//1~r1~l1~x
// 
//1e6x10
//1~n
int pri[1000009],cnt;
bool f[1000009];
int max(int x,int y){return x>y?x:y;}
void init(){
	memset(f,0,sizeof(f));f[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!f[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=1000000;j++){f[i*pri[j]]=1;if(i%pri[j]==0) break;}
	}
}
int T,x,p,k;
int a[19],tot;
vector<int > pk[2];
int Get(int n){
	pk[0].clear();pk[1].clear();
	int flag,sum=0,c;
	for(int i=1;i<(1<<tot);i++){
		c=1,flag=0;
		for(int j=1;j<=tot;j++){
			if(i&(1<<(j-1))) flag++,c*=a[j];	
		}
		if(flag&1){sum+=(n/c);pk[1].push_back(c);} 
		else{sum-=(n/c);pk[0].push_back(c);}
	}
	return (n-sum);
}
int get(int n){
	int sum=0;
	for(int i=0;i<pk[1].size();i++) sum+=(n/pk[1][i]);
	for(int i=0;i<pk[0].size();i++) sum-=(n/pk[0][i]);
	return (n-sum);
}
int main(){
	init();
	scanf("%d",&T);
	while(T--){
		tot=0;
		scanf("%d%d%d",&x,&p,&k);
		for(int i=1;i<=cnt&&pri[i]<=p;i++) if(p%pri[i]==0) a[++tot]=pri[i];
		int l=x+1,r=10000000,t=Get(x),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(get(mid)-t>=k) r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}