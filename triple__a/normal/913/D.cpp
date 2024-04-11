#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=500007;

int n,T;

struct ay{
	int num,p,t;
	friend bool operator<(ay x,ay y){
		return x.t<y.t;
	}
}xp[maxn];

int rb[maxn];

bool check(int k){
	int tm=0,cnt=0;
	for (int i=1;i<=n;++i){
		if (xp[i].p<k) continue;
		tm+=xp[i].t;
		rb[cnt++]=xp[i].num;
		if (cnt==k||tm>T) break;
	}
	if (cnt==k&&tm<=T){
		return 1;
	}
	return 0;
}

int ans(int l,int r){
	if (l==r){
		check(l);
		return l;
	}
	int md=(l+r)>>1;
	if (check(md+1)){
		return ans(md+1,r);
	}
	else{
		return ans(l,md);
	}
}

int main(){
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&xp[i].p,&xp[i].t);
		xp[i].num=i;
	}
	
	sort(xp+1,xp+n+1);
	int as=ans(0,n);
	printf("%d\n%d\n",as,as);
	for (int i=0;i<as;++i){
		printf("%d ",rb[i]);
	}
	return 0;
}