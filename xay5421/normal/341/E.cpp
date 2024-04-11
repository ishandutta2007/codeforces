// author: xay5421
// created: Thu Nov 11 22:01:00 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int n;
vector<pair<int,int> >ans;
struct node{
	int x,id;
	bool operator<(const node&k)const{return x>k.x;}
}a[N];
void sol(node&k1,node&k2,node&k3){
	int k=k2.x/k3.x;
	while(k){
		if(k&1){
			ans.eb(k3.id,k2.id);
			k2.x-=k3.x,k3.x<<=1;
		}else{
			ans.eb(k3.id,k1.id);
			k1.x-=k3.x,k3.x<<=1;
		}
		k>>=1;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n);
	if(!a[2].x)puts("-1"),exit(0);
	while(a[3].x){
		sol(a[1],a[2],a[3]);
		sort(a+1,a+1+n);
	}
	printf("%d\n",SZ(ans));
	for(auto x:ans)printf("%d %d\n",x.first,x.second);
	return 0;
}