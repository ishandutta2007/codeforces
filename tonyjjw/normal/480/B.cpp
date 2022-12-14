//*

#include<stdio.h>
#include<algorithm>
#define MN 100000

using namespace std;

int N,L;
int A[MN];

int p1,p2;

bool measure(int x,int s=0,int e=1e9){
	for(int l=0,r=0;l<N;l++){
		while(r<N && A[r]-A[l]<x)r++;
		if(r<N && A[r]-A[l]==x){
			if(s>A[l] || A[l]>e)continue;
			p1=A[l],p2=A[r];
			return true;
		}
	}
	return false;
}

int main(){
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	int x,y;
	scanf("%d%d%d%d",&N,&L,&x,&y);
	if(x>y)swap(x,y);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	if(measure(x) && measure(y)){
		puts("0");
		return 0;
	}
	if(measure(x)){
		printf("1\n%d",y);
		return 0;
	}
	if(measure(y)){
		printf("1\n%d",x);
		return 0;
	}
	if(measure(x+y)){
		printf("1\n%d",p1+x);
		return 0;
	}
	if(measure(y-x,0,L-y)){
		printf("1\n%d",p1+y);
		return 0;
	}
	if(measure(y-x,x,L)){
		printf("1\n%d",p1-x);
		return 0;
	}

	printf("2\n%d %d", x, y);
	return 0;
}

//*/