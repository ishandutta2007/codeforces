// author: xay5421
// created: Wed Sep  1 15:35:27 2021
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
using namespace std;
int ask(vector<pair<int,int> >vs){
	printf("? %d\n",SZ(vs));
	for(auto x:vs)printf("%d %d ",x.first,x.second);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	int S;
	{
		vector<pair<int,int> >v;
		rep(i,1,200)rep(j,1,200)v.emplace_back(i,j);
		S=ask(v);
	}
	int l=1,r=7,res=8,lst=0;
	while(l<=r){
		int mid=(l+r)>>1;
		vector<pair<int,int> >v;
		rep(i,1,200)if(i%(1<<mid)==0)rep(j,1,200)v.emplace_back(i,j);
		int cur=ask(v);
		if((cur<<mid)==S){
			l=mid+1;
		}else{
			r=mid-1;
			res=mid,lst=cur;
		}
	}
	int a=abs(S-(lst<<res))>>(res-1);
	int b=S/a;
	printf("! %d\n",(a+b-2)*2);
	fflush(stdout);
	return 0;
}