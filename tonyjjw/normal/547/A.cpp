//*
#include<stdio.h>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

typedef __int64 ll;

ll M;
ll h1,h2,a1,a2;
ll x1,x2,y1,y2;
ll s1,s2,t1,t2;

ll f(ll h,ll x,ll y){
	return (x*h+y)%M;
}

ll t(ll h,ll x,ll y){
	ll th=f(h,x,y),v=1;
	while(th!=h && v<M+1){
		th=f(th,x,y);
		v++;
	}
	if(v==M+1)return -1;
	return v;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%I64d",&M);
	scanf("%I64d%I64d",&h1,&a1);
	scanf("%I64d%I64d",&x1,&y1);
	scanf("%I64d%I64d",&h2,&a2);
	scanf("%I64d%I64d",&x2,&y2);
	while(h1!=a1 && s1<M){
		h1=f(h1,x1,y1);
		s1++;
	}
	if(s1==M){
		puts("-1");
		return 0;
	}
	t1=t(a1,x1,y1);
	while(h2!=a2 && s2<M){
		h2=f(h2,x2,y2);
		s2++;
	}
	if(s2==M){
		puts("-1");
		return 0;
	}
	t2=t(a2,x2,y2);
	while(s1<2*M*M || s2<2*M*M){
		if(s1==s2){
			printf("%I64d\n",s1);
			return 0;
		}
		if(s1<s2){
			if(t1==-1){
				puts("-1");
				return 0;
			}
			s1+=((s2-s1+t1-1)/t1)*t1;
		}
		else{
			if(t2==-1){
				puts("-1");
				return 0;
			}
			s2+=((s1-s2+t2-1)/t2)*t2;
		}
	}
	puts("-1");
	return 0;
}
//*