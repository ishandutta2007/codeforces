#include<cstdio>
#include<algorithm>
#define ll __int128_t

void wr(ll x){
	if(x>9)
		wr(x/10);
	putchar(x%10+'0');
}

inline int gcd(int x,int y){
	while(y){
		int tmp=x;
		x=y;
		y=tmp%y;
	}
	return x;
}

int T;

int m,d,w;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&m,&d,&w);
		w=w/gcd(w,d-1);
		m=std::min(m,d);
		d=m/w;
		wr((ll)w*(ll)d*(ll)(d-1)/(ll)2+((ll)m-(ll)d*(ll)w)*(ll)d);
		puts("");
	}
}