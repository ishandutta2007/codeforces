#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <iomanip>
#include<map>
#include <string>
#include<list>
#include<stack>
#include <queue>
using namespace std;


#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)



//#pragma comment(linker, "/STACK:167772160")

/*
int compare (const void* a, const void* b){
	return ((*(pair<int, int>*)b).first-(*(pair<int, int>*)a).first);

}*/
bool used[5];
int mas[5][5], ans(0), use[5], mans;

void perest(int a, int val){
	if(a==0){
		int q=((mas[use[0]][use[1]]+mas[use[1]][use[0]]+mas[use[2]][use[3]]+mas[use[3]][use[2]])+(mas[use[1]][use[2]]+mas[use[2]][use[1]]+mas[use[3]][use[4]]+mas[use[4]][use[3]])+(mas[use[2]][use[3]]+mas[use[3]][use[2]])+(mas[use[3]][use[4]]+mas[use[4]][use[3]]));
		ans=MAX(ans, q);
		used[val]=false;
		return;
	}
	for(int i(0); i<5; ++i){
		if(!used[i]){
			use[a-1]=i;
			used[i]=true;
			perest(a-1, i);
		}
	}
	if(val!=5)
		used[val]=false;
	return;
}

int main(){
	for(int i(0);i<5;++i)
		for(int j(0); j<5; ++j)
			scanf("%d", &mas[i][j]);
	memset(used, 0, 5);
	perest(5,5);
	printf("%d", ans);
	return 0;
}