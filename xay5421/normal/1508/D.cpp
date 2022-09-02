// author: xay5421
// created: Wed Apr 21 16:36:30 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=2005;
int n,x[N],y[N],a[N],fa[N],id[N];
bool vis[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int get(int i){
	if(x[i]==0&&y[i]==0)return 0;
	if(x[i]>0&&y[i]>=0)return 1;
	if(x[i]<=0&&y[i]>0)return 2;
	if(x[i]<0&&y[i]<=0)return 3;
	if(x[i]>=0&&y[i]<0)return 4;
	assert(0);
}
LL cross(int a,int b,int c,int d){
	return 1LL*a*d-1LL*b*c;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d",&x[i],&y[i],&a[i]),fa[i]=i,id[i]=i;
	int pos=-1;
	rep(i,1,n)if(a[i]!=i){
		pos=i;
		break;
	}
	if(pos==-1)puts("0"),exit(0);
	rep(i,1,n)if(!vis[i]){
		int x=i;
		while(!vis[x]){
			vis[x]=1;
			x=a[x];
			fa[fd(x)]=fd(i);
		}
	}
	{
		int x_=x[pos],y_=y[pos];
		rep(i,1,n)x[i]-=x_,y[i]-=y_;
	}
	sort(id+1,id+1+n,[&](int x,int y){
		//return atan2(::y[x],::x[x])<atan2(::y[y],::x[y]);
		int x_=get(x),y_=get(y);
		if(x_!=y_)return x_<y_;
		return cross(::x[x],::y[x],::x[y],::y[y])>0;
	});
	vector<pair<int,int> >ans;
	auto ps=[&](int x,int y){
		ans.emplace_back(x,y);
	};
	id[1]=id[n];
	rep(i,1,n-1)if(cross(x[id[i]],y[id[i]],x[id[i+1]],y[id[i+1]])>0&&fd(id[i])!=fd(id[i+1])){
		ps(id[i],id[i+1]);
		swap(a[id[i]],a[id[i+1]]);
		fa[fd(id[i])]=fd(id[i+1]);
	}
	while(a[pos]!=pos){
		ps(pos,a[pos]);
		swap(a[pos],a[a[pos]]);
	}
	rep(i,1,n)assert(a[i]==i);
	printf("%d\n",SZ(ans));
	for(const auto&x:ans)printf("%d %d\n",x.first,x.second);
	return 0;
}