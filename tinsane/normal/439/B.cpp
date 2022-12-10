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
#define ll long long
#define ld long double
#define uint unsigned int

// M_PI

#pragma comment(linker, "/STACK:167772160")


int compare (const void* a, const void* b){
    return ((*(ll*)a)-(*(ll*)b));

}

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
    ll sum(0),x,c[100000];
    int n;
    scanf("%d%I64d", &n, &x);
    for(int i(0);i<n;++i)
        scanf("%I64d", &c[i]);
    qsort(c,n,sizeof(ll), compare);
    for(int i(0); i<n;++i){
        sum+=c[i]*x;
        if(x>1)
            --x;
    }
    printf("%I64d", sum);
    return 0;
}