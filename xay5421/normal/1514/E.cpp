// author: xay5421
// created: Tue Apr 20 08:59:32 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=105;
int T,n,fa[N];
vector<int>vec;
bitset<N>ans[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int ask(int k1,int k2){
	printf("1 %d %d\n",k1,k2);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void deal(int x){
	if(vec.empty()){vec.push_back(x);return;}
	if(ask(x,*vec.begin()))vec.insert(vec.begin(),x);
	else if(ask(vec.back(),x))vec.push_back(x);
	else{
		int l=0,r=SZ(vec)-1;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(ask(x,vec[mid]))r=mid;
			else l=mid;
		}
		assert(r-l==1);
		vec.insert(vec.begin()+r,x);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,0,n-1)fa[i]=i,ans[i].reset();
		vec.clear();
		rep(i,0,n-1){
			deal(i);
		}
		int j=n-1;
		per(i,n-1,0){
			if(j>=i)--j;
			while(j>=0){
				printf("2 %d %d ",vec[i],j+1);
				per(k,j,0)printf("%d ",vec[k]);
				puts("");
				fflush(stdout);
				int x;
				scanf("%d",&x);
				if(!x)break;
				per(k,j,0){
					fa[fd(vec[i])]=fd(vec[k]);
					if(ask(vec[i],vec[k])){
						j=k-1;
						break;
					}
				}
			}
			rep(i,0,n-1)ans[fd(i)].set(i);
			per(i,n-2,0)ans[fd(vec[i])]|=ans[fd(vec[i+1])];
		}
		puts("3");
		rep(i,0,n-1){
			rep(j,0,n-1)putchar(ans[fd(i)][j]+48);
			puts("");
		}
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x==-1)exit(1);
	}
	return 0;
}