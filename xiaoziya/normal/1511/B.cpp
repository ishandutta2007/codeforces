#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int T,a,b,c;
long long x,y,z;
int getlen(int x){
	int res=0;
	while(x)
		x/=10,res++;
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c),a-=c,b-=c,c--;
		z=1;
		while(c--)
			z*=10;
		x=z;
		while(a--)
			while(1){
				x<<=1;
				if(getlen(x)>getlen(x/2))
					break;
			}
		y=z;
		while(b--)
			while(1){
				y*=3;
				if(getlen(y)>getlen(y/3))
					break;
			}
		printf("%lld %lld\n",x,y);
	}
	return 0;
}