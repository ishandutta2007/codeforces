// author: xay5421
// created: Mon Mar  1 00:12:37 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int pos=-1;
		rep(i,2,n){
			printf("? %d %d\n",i-1,1);
			rep(j,1,i-1)printf("%d%c",j,j==i-1?'\n':' ');
			printf("%d\n",i);
			fflush(stdout);
			int t;
			scanf("%d",&t);
			if(t){
				pos=i;
				break;
			}
		}
		int l=1,r=pos-1,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			printf("? %d %d\n",mid-l+1,1);
			rep(i,l,mid)printf("%d%c",i,i==mid?'\n':' ');
			printf("%d\n",pos);
			fflush(stdout);
			int t;
			scanf("%d",&t);
			if(t){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		vector<int>ans;
		rep(i,1,pos-1)if(i!=res){
			ans.push_back(i);
		}
		rep(i,pos+1,n){
			printf("? 1 1\n%d\n%d\n",pos,i);
			fflush(stdout);
			int t;
			scanf("%d",&t);
			if(!t)ans.push_back(i);
		}
		printf("! %d ",SZ(ans));
		for(int x:ans)printf("%d ",x);
		puts("");
		fflush(stdout);
	}
	return 0;
}