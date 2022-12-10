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
#define MODULATOR 1000000007 

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
int main(){
    int T;
    ll n,k,d1,d2;
    scanf("%d", &T);
    for(;T;--T){
        scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
        if(d1>d2)
            swap(d1, d2);
        if(n%3){
            printf("no\n");
            continue;
        }
        if(!((k-2*d2+d1)%3) && n-k>=d2+d1 && k-2*d2+d1>=0){
            printf("yes\n");
            continue;
        }
        if(!((k-d2-d1)%3) && n-k>=d2*2-d1 && k-d2-d1>=0){
            printf("yes\n");
            continue;
        }
        if(!((k-2*d2-d1)%3) && n-k>=2*d1+d2 && k-2*d2-d1>=0){
            printf("yes\n");
            continue;
        }
        if(!((k-2*d1-d2)%3) && n-k>=2*d2+d1 && k-2*d1-d2>=0){
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
    return 0;
}