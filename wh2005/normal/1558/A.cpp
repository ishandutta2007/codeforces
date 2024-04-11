#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,a,b,c[N];


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		//ABABABAB
		int x=0,g=0;
		if(a<=b){
			x=(b-a+1)/2,g=2*a+(b-a+1)/2;
		}
		else x=(a-b)/2,g=2*b+(a-b)/2;
		
		int y=0,h=0;
		swap(a,b);
		if(a<=b){
			y=(b-a+1)/2,h=2*a+(b-a+1)/2;
		}
		else y=(a-b)/2,h=2*b+(a-b)/2;
		int m=0;
		for(int i=0;i<=a+b;i++)
			if((i>=x&&i<=g&&(i-x)%2==0)||(i>=y&&i<=h&&(i-y)%2==0)){
				c[++m]=i;
			}
		printf("%d\n",m);
		for(int i=1;i<=m;i++) printf("%d ",c[i]);
		puts("");
	}	
	return 0;
}