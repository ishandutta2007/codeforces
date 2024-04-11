#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1005;
int n,d[N],q[N];vector<int>g[N];bool inq[N];
int query(int k1,int k2){
	printf("? %d %d\n",k1,k2);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void print(int k1){
	printf("! %d\n",k1);
	fflush(stdout);
	exit(0);
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int k1,k2;rd(k1),rd(k2);
		g[k1].push_back(k2),g[k2].push_back(k1);
		++d[k1],++d[k2];
	}
	int he=0,ta=0;
	for(int i=1;i<=n;++i)if(d[i]==1)q[++ta]=i,inq[i]=1;
	while(he!=ta){
		int k1=q[++he];
		if(he==ta)print(k1);
		int k2=q[++he];
		int tmp=query(k1,k2);
		if(tmp==k1||tmp==k2)print(tmp);
		for(auto k3:g[k1]){
			if(--d[k3]==1)q[++ta]=k3,inq[k3]=1;
		}
		for(auto k3:g[k2]){
			if(--d[k3]==1)q[++ta]=k3,inq[k3]=1;
		}
	}
	return 0;
}