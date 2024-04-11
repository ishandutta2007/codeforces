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
#include<set>
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
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define PLL pair<ll,ll>
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define V(a) vector<a>
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")

int comp(const void * a, const void* b){
    return (*(ll*)a)-(*(ll*)b);
}

int main(){
    int n;
    ll mas[300000], ans(0);
    scanf("%d", &n);
    for(int i(0);i<n;++i)
        scanf("%I64d", &mas[i]);
    qsort(mas, n, sizeof(ll), comp);
    for(int i(0); i<n;++i)
        ans+=mas[i]*(2+i);
    ans-=mas[n-1];
    printf("%I64d", ans);
    return 0;
}