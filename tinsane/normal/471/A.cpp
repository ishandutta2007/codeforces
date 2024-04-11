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
#include<functional>
#include<set>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define STR string
#define MAXINT 1000000010
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")

int main(){
    ios_base::sync_with_stdio(0);
    int mas[10],x;
    bool legs(0);
    for(int i(0);i<10;++i)
        mas[i]=0;
    for(int i(0);i<6;++i){
        cin>>x;
        --x;
        ++mas[x];
    }
    for(int i(0);i<10;++i){
        if(mas[i]==6){
            cout<<"Elephant";
            return 0;
        }
        if(mas[i]>=4)
            legs=1;
    }
    if(legs){
        for(int i(0);i<6;++i)
            if(mas[i]==2){
            cout<<"Elephant";
            return 0;
        }
        cout<<"Bear";
        return 0; 
    }
    cout<<"Alien";
    return 0;
}