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
#define MAXINT 1000000010

// M_PI

#pragma comment(linker, "/STACK:167772160")

/*
int compint (const void* a, const void* b){
    return ((*(int*)a)-(*(int*)b));
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
    ios_base::sync_with_stdio(0);
    int n,m,k, mas[2000];
    char buf[2000][2000];
    cin>>n>>m>>k;
    for(int i(0); i<m;++i)
        mas[i]=0;
    for(int i(0); i<n;++i)
        for(int j(0); j<m;++j)
            cin>>buf[i][j];
    for(int i(1); i<n;++i)
        for(int j(0); j<m;++j){
            switch(buf[i][j]){
            case 'L':
                if(j-i>=0)
                    ++mas[j-i];
                break;
            case 'U':
                if(!(i&1))
                    ++mas[j];
                break;
            case 'R':
                if(j+i<m)
                    ++mas[j+i];
                break;
            }
        };
    for(int i(0); i<m;++i)
        printf("%d ", mas[i]);
    return 0;
}