// author: xay5421
// created: Sun Apr 25 08:48:51 2021
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
const int MX=1e8;
int n,m;
int qry(int x,int y){
	printf("0 %d %d\n",x,y);
	fflush(stdout);
	int z;
	scanf("%d",&z);
	return z;
}
vector<int>vec,ans1,ans2;
void sol(int l,int r){
	//D("sol %d %d\n",l,r);
	if(l>r)return;
	int mid=(l+r)>>1;
	int d=qry(mid,mid);
	if(d==0)vec.push_back(mid),d=1;
	sol(l,mid-d),sol(mid+d,r);
}
void out(){
	sort(vec.begin(),vec.end());
	int p=-MX;
	for(int x:vec)if(p==x)++p;
	for(int x:vec){
		if(qry(p,x)==0)ans1.push_back(x);
		if(qry(x,p)==0)ans2.push_back(x);
	}
	printf("1 %d %d\n",SZ(ans2),SZ(ans1));
	for(int x:ans2)printf("%d ",x);
	puts("");
	for(int x:ans1)printf("%d ",x);
	puts("");
	fflush(stdout);
}
int main(){
	sol(-MX,MX);
	out();
	return 0;
}