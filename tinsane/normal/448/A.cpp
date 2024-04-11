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
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define uint unsigned int
#define MAXINT 1000000010
#define PII pair<int,int> 
#define PLL pair<ll,ll> 
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define VPII vector<pair<int, int>> 

// M_PI

#pragma comment(linker, "/STACK:167772160")


/*
int compint (const void* a, const void* b){
    return ((*(int*)a)-(*(int*)b));
}
*/
/*
int compPII (const void* a, const void* b){
    return ((*(pair<int, int>*)a).first-(*(pair<int, int>*)b).first);
}
*/
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



int main() {
    int a(0),b(0),n,x;
    for(int i(0); i<3;++i){
        scanf("%d", &x);
        a+=x;
    }
    for(int i(0); i<3;++i){
        scanf("%d", &x);
        b+=x;
    }
    scanf("%d", &n);
    n-=(b/10);
    if(b%10)
        --n;
    n-=a/5;
    if(a%5)
        --n;
    if(n>=0)
        printf("YES");
    else
        printf("NO");
    return 0;
}