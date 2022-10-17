#include <cstdio>
#include <iostream>
#include <algorithm>

typedef int INT;
#define int long long

#define MAXN 100005

int n,m,ans,c[MAXN],w[MAXN];
int val[MAXN];
bool vis[MAXN];

struct Heap{
	
	int SIZE;
	int q[MAXN];
	
	inline void push(int x){
		q[++SIZE]=x;
		int u=SIZE;
		
		while (u!=1 && val[q[u]]<val[q[u>>1]]) std::swap(q[u],q[u>>1]),u>>=1;
	}
	
	inline int& top(){ return q[1]; }
	
	inline void pop(){
		q[1]=q[SIZE--];
		int u=1,v;
		
		while ((u<<1)<=SIZE){
			v=u<<1;
			if ((v|1)<=SIZE && val[q[v|1]]<val[q[v]]) v|=1;
			if (val[q[v]]<val[q[u]]) std::swap(q[u],q[v]),u=v;
			else break;
		}
	}
} h;

INT main(){
	
	std::cin>>n>>m;
	for (int i=1;i<=n;i++) std::cin>>c[i]; 
	for (int i=1;i<=n;i++) std::cin>>w[i];
	
	for (int i=1;i<=n;i++){
		if (c[i]%100==0) continue;
		val[i]=w[i]*(100-c[i]%100);
		h.push(i);
		m-=c[i]%100;
		if (m<0){
			if (h.SIZE>0){
				vis[h.top()]=1;
				ans+=val[h.top()];
				h.pop();
				m+=100;
			}
		}
	}
	
	std::cout<<ans<<std::endl;
	
	for (int i=1;i<=n;i++){
		if (vis[i]){
			std::cout<<c[i]/100+1<<" "<<0<<std::endl;
		} else{
			std::cout<<c[i]/100<<" "<<c[i]%100<<std::endl;
		}
	}
	
	return 0;
	
}