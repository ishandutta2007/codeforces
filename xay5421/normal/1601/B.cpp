// author: xay5421
// created: Mon Oct 25 14:40:12 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005*10;
int n,a[300005],b[300005],ind,t[300005*4];
bool vis[N];
vector<pair<int,int> >e[N];
void bud(int k1,int k2,int k3){
	if(k2==k3){
		t[k1]=k2+n+1;
		e[t[k1]].eb(k2+b[k2],0);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	t[k1]=++ind;
	e[t[k1]].eb(t[k1*2],0);
	e[t[k1]].eb(t[k1*2+1],0);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		e[k6].eb(t[k1],1);
		return;
	}
	int mid=(k2+k3)>>1;
	add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
}
int dis[N],pre[N];
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);
	ind=n*2+1;
	bud(1,0,n);
	rep(i,1,n){
		add(1,0,n,max(i-a[i],0),i,i);
	}
	memset(dis,63,sizeof(dis));
	deque<int>q;
	dis[n]=0;
	q.push_back(n);
	while(!q.empty()){
		int k1=q.front();
		q.pop_front();
		if(vis[k1])continue;
		vis[k1]=1;
		for(auto x:e[k1])if(dis[k1]+x.second<dis[x.first]){
			pre[x.first]=k1;
			dis[x.first]=dis[k1]+x.second;
			if(x.second==0){
				q.push_front(x.first);
			}else{
				q.push_back(x.first);
			}
		}
	}
	if(dis[n+1]>1e9)puts("-1"),exit(0);
	printf("%d\n",dis[n+1]);
	vector<int>v;
	for(int i=n+1;i;i=pre[i]){
		if(i>n&&i<=n*2+1)v.pb(i-n-1);
	}
	reverse(v.begin(),v.end());
	for(auto x:v)printf("%d ",x);
	return 0;
}