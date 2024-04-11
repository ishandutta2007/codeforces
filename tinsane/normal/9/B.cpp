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
    double mint(MAXINT),vb, vs;
    ll n, mas[100], x,y, mino;
    cin>>n>>vb>>vs;
    for(int i(0);i<n;++i)
        cin>>mas[i];
    cin>>x>>y;
    for(int i(1);i<n;++i){
        double t=(mas[i]-mas[0])/vb+(sqrt((x-mas[i])*(x-mas[i])*1.0+y*y))/vs;
        if(t<mint || (t==mint && (x-mas[i])*(x-mas[i])<(x-mas[mino])*(x-mas[mino]))){
            mino=i;
            mint=t;
        }
    }
    cout<<mino+1;
    return 0;
}