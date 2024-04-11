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
    //ios_base::sync_with_stdio(0);
    int mas[256], ans(0);
    char s;
    cin>>s;
    for(int i(0); i<256; ++i)
        mas[i]=0;
    while(s!='}'){
        cin>>s;
        ++mas[s];
    }
    --ans;
    for(int i(0); i<256; ++i)
        if(mas[i])
            ++ans;
    if(mas[',']) --ans;
    cout<<ans;
    return 0;
}