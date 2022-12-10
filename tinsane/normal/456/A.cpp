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
#include <time.h>
#include<functional>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define MAXINT 1000000010
#define PII pair<int,int> 
#define PLL pair<ll,ll>
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define V(a) vector<a>
#define _10POW9PLUS7 1000000007 
//  8739
// M_PI

#pragma comment(linker, "/STACK:167772160")


/*
int compint (const void* a, const void* b){
    return ((*(int*)a)-(*(int*)b));
}
*/

int compPII (const void* a, const void* b){
    return ((*(PII*)a).first-(*(PII*)b).first);
}

/*
int compll (const void* a, const void* b){
    return ((*(ll*)a)-(*(ll*)b));
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
    int n, maxc(0);
    PII mas[100000];
    scanf("%d", &n);
    for(int i(0); i<n;++i)
        scanf("%d%d", &mas[i].first, &mas[i].second);
    qsort(mas, n, sizeof(PII), compPII);
    for(int i(0); i<n;++i)
        if(mas[i].second<maxc){
            printf("Happy Alex");
            return 0;
        }
        else
            maxc=mas[i].second;
    printf("Poor Alex");
    return 0;
}