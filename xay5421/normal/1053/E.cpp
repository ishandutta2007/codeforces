#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repv(i,v) for(auto i=(v).begin();i!=(v).end();++i)
#define PB push_back
using namespace std;
const int N=1000005;
int n,a[N],pre[N],nxt[N],nxtsame[N],cur=1,used[N];
void NO(){puts("no"),exit(0);}
int get(){
	while(cur<=n&&used[cur])++cur;
	if(cur>n){
		NO();
	}
	return used[cur]=1,cur;
}
void sol(int l,int r,int rt=0){
	if(l>r)return;
	list<int>v;
	rep(i,l,r){
		int j=i;
		for(;nxtsame[j];j=nxtsame[j]){
			sol(j+1,nxtsame[j]-1,a[i]);
		}
		i=j;
		v.PB(i);
		if(i>r)NO();
	}
	int ned=(SZ(v)+1)/2;
	int cnt=0;
	for(auto x:v)if(a[x])++cnt;
	for(auto x:v)if(!a[x]&&cnt<ned){
		a[x]=get();
		++cnt;
	}
	for(auto it=v.begin();it!=v.end();++it){
		while(1){
			if(it!=v.begin()){
				auto k1=prev(it);
				if(k1!=v.begin()){
					auto k2=prev(k1);
					if(a[*it]==0&&a[*k1]&&a[*k2]){
						a[*it]=a[*k2];
						v.erase(it);
						v.erase(k1);
						it=k2;
						continue;
					}
					if(a[*it]&&a[*k1]&&a[*k2]==0){
						a[*k2]=a[*it];
						v.erase(it);
						v.erase(k1);
						it=k2;
						continue;
					}
				}
			}
			break;
		}
	}
	for(auto x:v)if(!a[x])a[x]=rt;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n*2-1)scanf("%d",&a[i]),used[a[i]]=1;
	rep(i,1,n*2-2)if(a[i]&&a[i]==a[i+1])NO();
	if(a[1]&&a[n*2-1]&&a[1]!=a[n*2-1])NO();
	a[1]=a[n*2-1]=a[1]|a[n*2-1];
	static int lst[N];
	per(i,n*2-1,1){
		if(a[i]&&lst[a[i]])nxtsame[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	sol(1,n*2-1);
	rep(i,1,n*2-2)if(a[i]&&a[i]==a[i+1])NO();
	puts("yes");
	rep(i,1,n*2-1)printf("%d ",a[i]);
	return 0;
}