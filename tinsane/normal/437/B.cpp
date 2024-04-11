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

//#pragma comment(linker, "/STACK:167772160")

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
    stack<int> ans;
    ll sum(0);
    ll n,lim, mas[19];
    scanf("%I64d%I64d", &n, &lim);
    for(int i(18); i>=0; --i){
        int k=1<<i;
        for(int j(1); j*k<=lim;j+=2){
            if(n>=k){
                n-=k;
                ans.push(j*k);
            }
            else
                break;
        }
    }
    if(n){
        printf("-1");
        return 0;
    }
    printf("%d\n", ans.size());
    while(!ans.empty()){
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}