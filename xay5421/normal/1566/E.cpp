// author: xay5421
// created: Sun Sep 12 23:16:30 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int T,n,dep[N],tmp;
vector<int>e[N];
vector<int>v;
int dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1;
	int tot=0;
	for(auto x:e[k1])if(x!=k2){
		tot+=dfs1(x,k1);
	}
	if(tot>0){
		if(k1!=1)v.push_back(tot);
		else tmp=tot;
		return 0;
	}
	return 1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		v.clear();
		tmp=0;
		rd(n);
		rep(i,1,n)e[i].clear();
		rep(i,2,n){
			int k1,k2;
			rd(k1),rd(k2);
			e[k1].push_back(k2),e[k2].push_back(k1);
		}
		dfs1(1,0);
		if(tmp==0){
			int sum=1;
			for(auto x:v){
				sum+=x-1;
			}
			pt(sum,'\n');
		}else{
			int sum=0;
			if(v.empty()){
				printf("%d\n",tmp);
			}else{
				sum=tmp;
				for(auto x:v){
					sum+=x-1;
				}
				pt(sum,'\n');
			}
		}
	}
	return 0;
}