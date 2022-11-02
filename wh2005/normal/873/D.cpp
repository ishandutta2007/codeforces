#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string>
#include <cstring>
#include <map> 
using namespace std;
int n,k,R[100009],L[100009];
int dat[100009];
void dfs(int l,int r,int cnt){
	cnt-=1;
	if(cnt==0){
		int x=0,len=r-l;
		while(len>0){
			x=R[x];printf("%d ",x);
			R[L[x]]=R[x],L[R[x]]=L[x];
			len--;
		}
		return ;
	}
	int mid=(l+r)/2;
	int num=2*(mid-l)-1;
	if(cnt==2){
		int x=0,len=r-l;
		for(int i=1;i<=len;i++){
			x=R[x];dat[i]=x;
			R[L[x]]=R[x],L[R[x]]=L[x];
		}
		for(int i=l;i<mid;i++) printf("%d ",dat[len-mid+i+1]);
		for(int i=1;i<=len-(mid-l);i++) printf("%d ",dat[i]);
		return ;
	}
	if(cnt<num){
		dfs(l,mid,cnt-1);
		dfs(mid,r,1);
		return ;
	}  
	if(cnt>num){
		int x=0,len=mid-l;
		for(int i=1;i<=len;i++){
			x=R[x];dat[i]=x;
			R[L[x]]=R[x],L[R[x]]=L[x];
		}
		for(int i=len;i>=1;i--) printf("%d ",dat[i]);
		dfs(mid,r,cnt-num);
		return ;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	if(k%2==0||k>2*n-1){printf("-1\n");return 0;}
	for(int i=0;i<=n;i++) R[i]=i+1;
	for(int i=n+1;i>=1;i--) L[i]=i-1;
	dfs(0,n,k);
	return 0;
}