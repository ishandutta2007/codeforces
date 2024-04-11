// author: xay5421
// created: Sun May 30 21:03:06 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int T,n,ans[100005];
int query(int k1,int k2,int k3){
	printf("? %d %d %d\n",k1,k2,k3);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	D("x=%d\n",x);
	return x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int a=-1,b=-1;
		rep(i,1,14)rep(j,i+1,14)rep(k,j+1,14){
			if(query(i,j,k)<=(n-4)/6){
				a=i,b=j;
				goto _;
			}
		}
		_:;
		D("!\n");
		assert(a!=-1);
		map<int,vector<int> >mp;
		rep(i,1,n)if(i!=a&&i!=b){
			mp[query(i,a,b)].push_back(i);
		}
		int key=(--mp.end())->first;
		assert(mp.count(key-1));
		if(SZ(mp[key-1])>=2){
			if(query(mp[key][0],mp[key-1][0],a)>query(mp[key][0],mp[key-1][1],a))swap(mp[key-1][0],mp[key-1][1]);
		}
		int k1=mp[key][0],k2=mp[key-1][0];
		ans[k1]=1,ans[k2]=2;
		rep(i,1,n)if(i!=k1&&i!=k2){
			ans[i]=query(i,k1,k2)+2;
		}
		if(ans[1]>ans[2]){
			rep(i,1,n)ans[i]=n-ans[i]+1;
		}
		printf("! ");
		rep(i,1,n)printf("%d%c",ans[i],i==n?'\n':' ');
		fflush(stdout);
		int x;
		scanf("%d",&x);
	}
	return 0;
}