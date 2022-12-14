#include <cstdio>
#define max_lgn 100000
using namespace std;
int n[max_lgn+2];
int main(){
	int*ed=n,m;
	while(scanf("%1d",++ed)==1);
	if(!(m=(--ed)-n)&&(n[0]&1)){
		puts("0");
		return 0;
	}
	int*i=n+1,*j=ed;
	if(*i!=*j){
		*(i+1)+=10;
		(--*i)||(++i);
	}
	for(; i<=j; ++i,--j){
		if(*i!=*j){
			*i-*j>9&&(*j+=10,--*(j-1));
			*i==*j+1&&(--*i,*(i+1)+=10);
		}
		if(*i!=*j||*i>18||*j>18||*i<0||*j<0){
			puts("0");
			return 0;
		}
		if(i==j){
			if((*i)&1){
				puts("0");
				return 0;
			}
			*i>>=1;
			break;
		}
		else
			*i=*i+1>>1,*j>>=1;
	}
	for(i=n; !*++i; );
	for(putchar(*i|'0'); ++i<=ed; putchar(*i|'0'));
	return 0;
}