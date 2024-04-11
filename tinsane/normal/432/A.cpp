#include <stdio.h>
//#include <fstream>
#include <stdlib.h>
#include <iostream>
//#include <vector>
//#include <deque>
//#include <math.h>
//#include <iomanip>
//#include<map>
#include <string>
//#include<list>
#include<stack>
//#include <queue>
using namespace std;
/*
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
*/
//#pragma comment(linker, "/STACK:167772160")
/*
int compare (const void* a, const void* b){
    return ((*(pair<int,pair<int, int>>*)b).first-(*(pair<int,pair<int, int>>*)a).first);
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
/*
long long gcd(long long a, long long b){
    if(a%b)
        return gcd(b, a%b);
    else
        return b;
}*/

int main(){
    //ios_base::sync_with_stdio(false);
    int n, k, s, cou(0);
    scanf("%d %d", &n, &k);
    for(int i(0); i<n;++i){
        scanf("%d", &s);
        if(k+s<6)
            ++cou;
    }
    printf("%d", (cou/3));
    return 0;
}