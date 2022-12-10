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
    int n,d,mas[100], s(0);
    scanf("%d%d", &n, &d);
    for(int i(0); i<n;++i){
        scanf("%d", &mas[i]);
        s+=mas[i]+10;
    }
    s-=10;
    if(s>d)
        printf("-1");
    else{
        printf("%d", (d-(s-(n-1)*10))/5);
    }
    return 0;
}