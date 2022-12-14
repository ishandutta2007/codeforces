//*
#include<stdio.h>
#include<algorithm>
#define MN 5000

using namespace std;

struct EXAM{
	int a,b;
	bool operator <(EXAM A)const{
		if(a!=A.a)return a<A.a;
		return b<A.b;
	}
}e[MN];

int N;

int main(){
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&e[i].a,&e[i].b);
	}
	sort(e,e+N);
	int day=e[0].b;
	for(int i=1;i<N;i++){
		if(e[i].b<day){
			day=e[i].a;
		}
		else{
			day=e[i].b;
		}
	}
	printf("%d",day);
	return 0;
}

//*/