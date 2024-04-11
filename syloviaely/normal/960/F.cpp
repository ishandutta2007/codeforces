#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=100000;
struct tree{
	int l,r,ma;
}t[N*40];
int root[N+10],len,n,m;
int find(int k1,int k2,int k3,int k4,int k5){
	if (k1==0||k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return t[k1].ma;
	int mid=k2+k3>>1;
	return max(find(t[k1].l,k2,mid,k4,k5),find(t[k1].r,mid+1,k3,k4,k5));
}
void insert(int k1,int k2,int k3,int k4,int k5){
	t[k1].ma=max(t[k1].ma,k5);
	if (k2==k3) return;
	int mid=k2+k3>>1;
	if (mid>=k4){
		if (t[k1].l==0) t[k1].l=++len;
		insert(t[k1].l,k2,mid,k4,k5);
	} else {
		if (t[k1].r==0) t[k1].r=++len;
		insert(t[k1].r,mid+1,k3,k4,k5);
	}
}
int main(){
	scanf("%d%d",&n,&m); len=0; int ans=0;
	for (int i=1;i<=m;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		int num=find(root[k1],0,N,0,k3-1)+1; //cout<<"fa "<
		ans=max(ans,num);
		if (root[k2]==0) root[k2]=++len;
		insert(root[k2],0,N,k3,num);
	}
	cout<<ans<<endl;
}