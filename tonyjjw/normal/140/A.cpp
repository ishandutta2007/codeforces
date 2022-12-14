//*

#include<stdio.h>
#include<math.h>
//#pragma warning(disable:4996)

int n,r,R;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&R,&r);
	if(2*r>R){
		if(n==1 && r<=R){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	else{
		if(asin((double)r/(R-r))*n<=atan2(0.0,-1.0)+0.0000001){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}

//*/