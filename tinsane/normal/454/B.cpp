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
}*/

/*
int compPII (const void* a, const void* b){
    return ((*(pair<int, int>*)b).first-(*(pair<int, int>*)a).first);
}*/

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
    int n, mas[100000], x;
    bool f(0);
    scanf("%d", &n);
    x=n;
    scanf("%d", &mas[0]);
    for(int i(1); i<n;++i){
        scanf("%d", &mas[i]);
        if(!f){
            if(mas[i]<mas[i-1]){
                f=1;
                x=i;
            }
        }
        else{
            if(mas[i]<mas[i-1]){
                printf("-1");
                return 0;
            }
        }
    }
    if(f && mas[n-1]>mas[0]){
        printf("-1");
        return 0;
    }
    printf("%d", n-x);
    return 0;
}