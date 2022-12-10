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
int main() 
{
	//ios_base::sync_with_stdio(false);
	int m,n, mas[100], cou(0), sum(0);
	scanf("%d%d", &n, &m);
	for(int i(0); i<n;++i)
		scanf("%d", &mas[i]);
	for(int i(0); i<n;++i){
		if(sum+mas[i]>m){
			++cou;
			sum=mas[i];
		}
		else
			sum+=mas[i];
	}
	if(sum)
		++cou;
	printf("%d", cou);
	return 0;
}