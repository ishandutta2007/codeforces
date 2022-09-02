// author: xay5421
// created: Tue Aug 24 23:07:17 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=2025;
int T,n,a[N];
vector<int>v;
void ps(int x,int&pos1,int&pos2){
	assert(x&1);
	v.push_back(x);
	if(pos1<=x)pos1=x+1-pos1;
	if(pos2<=x)pos2=x+1-pos2;
	reverse(a+1,a+1+x);
}
void sol(){
	v.clear();
	rep(i,1,n)if((a[i]&1)!=(i&1))throw 0;
	for(int i=n;i>=2;i-=2){
		int pos1=-1,pos2=-1;
		per(j,i,1){
			if(a[j]==i)pos1=j;
			if(a[j]==i-1)pos2=j;
		}
		if(abs(pos1-pos2)!=1){
			ps(pos1,pos1,pos2);
			ps(pos2-1,pos1,pos2);
		}
		if(pos1+1==pos2&&pos1!=1){
			ps(pos1+2,pos1,pos2);
		}
		if(pos1-1==pos2&&pos1!=i){
			ps(pos1,pos1,pos2);
		}
		if(pos1+1==pos2){
			assert(pos1==1);
			ps(i,pos1,pos2);
		}
	}
	printf("%d\n",SZ(v));
	for(auto x:v)printf("%d ",x);
	puts("");
	throw 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		try{
			sol();
		}catch(int x){
			if(x==0){
				puts("-1");
			}
		}
	}
	return 0;
}