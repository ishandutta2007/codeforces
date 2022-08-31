#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int n,d,K,m;
const int N=110000;
int a[N];
int A[N];
int cango(int k1,int k2){
	if (k1<=(n+1)/2) return (abs(k1-k2)<=1ll*k1*d);
	else return (abs(k1-k2)<=1ll*d*(n-k1+1));
}
int check(int no){
	for (int i=1;i<=n;i++)
		if (i>no&&i<n-no+1) A[i]=K; else A[i]=0;
	for (int i=1;i<=n;i++) A[i]+=A[i-1];
	int now=1;
//cout<<"fa "<<no<<endl;
//for (int i=1;i<=n;i++) cout<<A[i]<<" "; cout<<endl;
	int w=0; 
	for (int i=1;i<=n;i++){
		while (now<=n&&cango(i,now)){
			w+=a[now]; now++;
		}
//cout<<"fa1 "<<i<<" "<<w<<endl;
		if (A[i]>w) return 0;
	}
	w=0; now=n;
	for (int i=n;i;i--){
		while (now&&cango(i,now)){
			w+=a[now]; now--;
		}
	//	cout<<"fa2 "<<i<<" "<<w<<endl;
		if (A[n]-A[i-1]>w) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&d,&K); m=(n+1)/2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int lim=(n+1)/2;
	int l=0,r=lim+1,ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (check(mid)){
			ans=mid; r=mid;
		} else l=mid+1;
	}
	cout<<ans<<endl; return 0;
}