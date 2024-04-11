#include <stdio.h>
//#include <fstream>
#include <stdlib.h>
#include <iostream>
//#include <vector>
//#include <deque>
//#include <math.h>
//#include <iomanip>
//#include<map>
#include <string>
//#include<list>
#include<stack>
//#include <queue>
using namespace std;
/*
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
*/
#pragma comment(linker, "/STACK:167772160")
/*
int compare (const void* a, const void* b){
	return ((*(pair<int,pair<int, int>>*)b).first-(*(pair<int,pair<int, int>>*)a).first);
}*/
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
/*
long long gcd(long long a, long long b){
	if(a%b)
		return gcd(b, a%b);
	else
		return b;
}*/

int main(){
	//ios_base::sync_with_stdio(false);
	int  mas[100000], form[100000],x;
	long long  cou(0), n;
	scanf("%I64d", &n);
	for(int i(0); i<n;++i)
		mas[i]=0;
	for(int i(0); i<n;++i){
		scanf("%d %d", &x, &form[i]);
		--x;
		--form[i];
		++mas[x];
	}
	for(int i(0); i<n;++i){
		printf("%I64d %I64d\n", n-1+mas[form[i]], (n-1)-mas[form[i]]);
	}
	return 0;
}