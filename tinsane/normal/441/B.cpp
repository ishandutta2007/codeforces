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
    return ((*(pair<int, int>*)a).first-(*(pair<int, int>*)b).first);

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
    int n,v, res(0), dval, maxd(0);
    pair<int,int> mas[3001];
    scanf("%d%d", &n, &v);
    for(int i(0);i<n;++i){  
        scanf("%d%d", &mas[i].first, &mas[i].second);
        maxd=MAX(maxd, mas[i].first);
    }
    maxd+=2;
    qsort(mas,n,sizeof(pair<int,int>), compare);
    for(int i(1), j(0); i<maxd; ++i){
        dval=v;
        for(;j<n && dval;++j){
            if(mas[j].first==i || mas[j].first==i-1)
                if(mas[j].second<=dval){
                    res+=mas[j].second;
                    dval-=mas[j].second;
                    mas[j].second=0;
                }
                else{
                    res+=dval;
                    mas[j].second-=dval;
                    break;
                }
            else if(mas[j].first>i)
                break;
        }
    }
    printf("%d", res);
    return 0;
}