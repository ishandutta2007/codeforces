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

int compd (const void* a, const void* b){
    double ab(*(double*)a),bb(*(double*)b);
    if(ab-bb>0)
        return 1;
    else if(ab-bb<0)
        return -1;
    else
        return 0;
}

int main(){
    //ios_base::sync_with_stdio(0);]
    int n;
    double mas[100], ans(0), loc;
    cin>>n;
    for(int i(0); i<n;++i)
        cin>>mas[i];
    qsort(mas, n, sizeof(double), compd);
    if(mas[n-1]>=0.5)
        cout<<setprecision(10)<<fixed<<mas[n-1];
    else{
        loc=mas[n-1];
        for(int i(n-2);ans<loc && i>=0;--i){
            ans=loc;
            loc*=(1-mas[i]);
            double val(mas[i]);
            for(int j(i+1); j<n;++j)
                val*=(1-mas[j]);
            loc+=val;
        }
        if(ans<loc)
            ans=loc;
        cout<<setprecision(10)<<fixed<<ans;
    }
    return 0;
}