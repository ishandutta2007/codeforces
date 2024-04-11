#include <iostream>
using namespace std;

int a, b, f, k, ans, fuel;

int main(){
	scanf("%d%d%d%d",&a,&b,&f,&k);
	if((k == 1 && (b < a-f || b < f))
		||(k == 2 && (b < 2*(a-f) || b < f))
		||((2*(a-f) > b || 2*(f) > b)&&k>2)){
		printf("-1"); return 0;
	}
	fuel = b-f;
	for(int i=0;i<k-1;i++){
		if(i%2==0){
			if(fuel < 2*(a-f)){fuel = b; ans++;}
			fuel -= 2*(a-f);
		}
		else{
			if(fuel < 2*f){fuel = b; ans++;}
			fuel -= 2*f;
		}
	}
	if(k%2 == 0 && fuel < f) ans++;
	else if(k%2 == 1 && fuel < (a-f)) ans++;
	printf("%d\n",ans);
	return 0;
}