//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,h=0,ans=0,ener=0,a;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a);
		ener+=h-a;
		if(ener<0)ans-=ener,ener=0;
		h=a;
	}
	printf("%d",ans);
	return 0;
}

//*/