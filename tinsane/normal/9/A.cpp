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
    int n,m;
    cin>>n>>m;
    n=MAX(n,m);
    if(n==1)
        cout<<"1/1";
    else if (n==2)
        cout<<"5/6";
    else if(n==3)
        cout<<"2/3";
    else if(n==4)
        cout<<"1/2";
    else if(n==5)
        cout<<"1/3";
    else if(n==6)
        cout<<"1/6";
    return 0;
}