#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;
long long tmp[MN], N, M, L, i, j, x, mx,wtf;
struct wts{long long a,b,c,d;}temp[MN],ans;
void mrg(wts&i,wts j){
	wts tmp={0,0,0,0};
	tmp.a=i.a+j.a; tmp.b=max(i.b,i.a+j.b);
	tmp.c=max(j.c,j.a+i.c); 
	tmp.d=max(i.c+j.b,max(i.d,j.d));
	i = tmp;
}

int main(){
	for(scanf("%lld%lld",&N,&M),i=1;i<=N;i++){
		temp[i].b=temp[i].c=temp[i].d=-1LL<<60;
		for(scanf("%lld",&L),mx=wtf=0,j=1;j<=L;j++){
			scanf("%lld",&x);tmp[j]=x;
			temp[i].a+=x; mx+=x; wtf+=x;
			temp[i].b=max(temp[i].b,mx);
			temp[i].d=max(temp[i].d,wtf);
			if(wtf<0) wtf=0;
		}
		for(mx=0,j=L;j>=1;j--)
			mx+=tmp[j],temp[i].c=max(temp[i].c,mx);
	}
	scanf("%lld",&x); ans=temp[x];
	for(i=2;i<=M;i++){
		scanf("%lld",&x);
		mrg(ans, temp[x]);
	}
	printf("%lld\n",ans.d);
	return 0;
}