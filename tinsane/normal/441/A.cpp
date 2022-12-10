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
    return ((*(int*)a)-(*(int*)b));

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
    queue<int> prod;
    bool f;
    int n,v, t, x;
    scanf("%d%d", &n, &v);
    for(int i(0); i<n;++i){
        scanf("%d", &t);
        f=false;
        for(int j(0); j<t;++j){
            scanf("%d", &x);
            if(x<v && !f){
                prod.push(i+1);
                f=true;
            }
        }
    }
    printf("%d\n", prod.size());
    while(!prod.empty()){
        printf("%d ", prod.front());
        prod.pop();
    }
    return 0;
}