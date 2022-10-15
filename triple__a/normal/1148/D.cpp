#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=300007;
struct tup{
	int u,v,pos;
	friend bool operator< (tup x,tup y){
		if (x.v<y.v){
			return 1;
		}
		return 0;
	}
}ans[maxn];
int rec[maxn],n;

int solve(){
	int cnt=0;
	rec[cnt++]=n;
	ans[n].v=2*n+1;
	for (int i=n-1;i>=0;--i){
		if (ans[i].u<ans[rec[cnt-1]].v&&ans[i].u<ans[i].v){
			rec[cnt++]=i;
		}
	}
	return cnt;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d%d",&ans[i].u,&ans[i].v);
		ans[i].pos=i;
	}
	sort(ans,ans+n);
	int cnt1=solve()-1;
	int tmp[maxn];
	for (int i=1;i<=cnt1;++i){
		tmp[i]=ans[rec[i]].pos+1;
	}
	for (int i=0;i<n;++i){
		ans[i].u=-ans[i].u;
		ans[i].v=-ans[i].v;
	}
	sort(ans,ans+n);
	int cnt=solve()-1;
	if (cnt<=cnt1){
		printf("%d\n",cnt1);
		for (int i=1;i<=cnt1;++i){
			printf("%d ",tmp[i]);
		}
	} 
	else{
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;++i){
			printf("%d ",ans[rec[i]].pos+1);
		}
	}
	return 0;
}