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

// M_PI

#pragma comment(linker, "/STACK:167772160")

/*
int compare (const void* a, const void* b){
    return ((*(pair<int, int>*)b).first-(*(pair<int, int>*)a).first);

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

int main(){
    bool mas[100001];
    int a,n;
    scanf("%d", &n);
    for(int i(0);i<n;++i    )
        mas[i]=false;
    for(int i(0); i<n-1;++i){
        scanf("%d", &a);
        mas[a]=true;
    }
    for(int i(1); i<=n;++i){
        if(!mas[i]){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}