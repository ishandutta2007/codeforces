//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define push_back pb
#define emplace_back eb
#define make_tuple mt
using namespace std;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	if(n1<=n2){
		puts("Second");
	}
	else{
		puts("First");
	}
	return 0;
}
//*/