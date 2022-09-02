#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int query(const vector<int>&v1,const vector<int>&v2,int u){
	if(v1.empty()||v2.empty())return 0;
	printf("%d\n",(int)v1.size());
	for(auto&x:v1)printf("%d ",x);
	puts("");
	printf("%d\n",(int)v2.size());
	for(auto&x:v2)printf("%d ",x);
	puts("");
	printf("%d\n",u);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
const int N=505;
int n,sz[N],id[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		if(i==1){
			sz[i]=n;
		}else{
			vector<int>v1={1};
			vector<int>v2;
			rep(j,2,n)v2.pb(j);
			sz[i]=query(v1,v2,i);
		}
	}
	iota(id+1,id+n+1,1);
	sort(id+1,id+n+1,[&](int x,int y){return sz[x]<sz[y];});
	vector<pair<int,int> >ans;
	vector<int>ban(n+1);
	rep(ii,1,n){
		int last=ii-1;
		while(1){
			int l=1,r=last,res=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				vector<int>v1={1};
				vector<int>v2;
				per(i,last,mid)if(!ban[i]){
					v2.pb(id[i]);
				}
				if(query(v1,v2,id[ii])){
					res=mid,l=mid+1;
				}else{
					r=mid-1;
				}
			}
			if(res!=-1){
				D("ans.eb(%d,%d)\n",id[ii],id[res]);
				ans.eb(id[ii],id[res]);
				ban[res]=1;
				last=res-1;
			}else{
				break;
			}
		}
	}
	printf("ANSWER\n");
	for(auto&x:ans)printf("%d %d\n",get<0>(x),get<1>(x));
	fflush(stdout);
	return 0;
}