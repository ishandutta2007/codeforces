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
#include<algorithm>
#include <queue>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)

// M_PI

//#pragma comment(linker, "/STACK:167772160")

/*
int compare (const void* a, const void* b){
	return ((*(int*)a)-(*(int*)b));

}
*/
/*
int compstr(const void* a, const void* b){
	if(*(string*)a>*(string*)b)
		return 1;
	else if(*(string*)a==*(string*)b)
		return 0;
	else
		return -1;
}
*/

int main(){
	int n,pos(0), mas[1001], min(0), max(0), sum(0), lsum(0);
	char ans[1001][1001];
	scanf("%d", &n);
	for(int i(0); i<n;++i){
		scanf("%d", &mas[i]);
		if(i%2)
			sum-=mas[i];
		else
			sum+=mas[i];
		lsum+=mas[i];
		min=MIN(min, sum);
		max=MAX(max, sum);
	}
	--max;
	for(int i(0); i<=max-min;++i)
		for(int j(0); j<lsum;++j)
			ans[i][j]=' ';
	for(int i(0),cou(0); i<lsum;){
		if(cou%2){
			for(;mas[cou]; --mas[cou]){
				ans[max-pos][i]='\\';
				++i;
				--pos;
			}
			++pos;
		}
		else{
			for(;mas[cou]; --mas[cou]){
				ans[max-pos][i]='/';
				++pos;
				++i;
			}
			--pos;
		}
		++cou;
	}
	for(int i(0); i<=max-min; ++i){
		for(int j(0); j<lsum;++j)
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}