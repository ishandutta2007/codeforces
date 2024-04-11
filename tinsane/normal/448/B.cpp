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
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define uint unsigned int
#define MAXINT 1000000010
#define PII pair<int,int> 
#define PLL pair<ll,ll> 
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define VPII vector<pair<int, int>> 

// M_PI

#pragma comment(linker, "/STACK:167772160")


/*
int compint (const void* a, const void* b){
    return ((*(int*)a)-(*(int*)b));
}
*/
/*
int compPII (const void* a, const void* b){
    return ((*(pair<int, int>*)a).first-(*(pair<int, int>*)b).first);
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



int main() {
    string s,t;
    int mass[255], mast[255], ans(0), k(0), r(0);
    cin>>s>>t;
    for(int i(0); i<255;++i)
        mass[i]=mast[i]=0;
    for(int i(0); i<s.size();++i)
        ++mass[s[i]];
    for(int i(0); i<t.size();++i)
        ++mast[t[i]];
    if(s.size()<t.size()){
            cout<<"need tree";
            return 0;
    }
    for(int i(0); i<255;++i){
        if(mass[i]<mast[i]){
            cout<<"need tree";
            return 0;
        }
        if(mass[i]>mast[i])
            ans=1;
    }
    for(;r<t.size() && k<s.size();++r){
        for(; k<s.size() && s[k]!=t[r] ;++k);
        ++k;
    }
    if(r<t.size())
        if(ans)
            printf("both");
        else
            printf("array");
    else
        printf("automaton");
    return 0;
}