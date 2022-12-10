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
#define ull unsigned long long
#define uint unsigned int
#define MAXINT 1000000010
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define PLL pair<ll,ll>
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define V(a) vector<a>
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")

int main(){
    int n;
    int cou[102][102];
    char mas[102][102];
    cin>>n;
    ++n;
    for(int i(0); i<n;++i)
        mas[i][n]=mas[n][i]=mas[i][0]=mas[0][i]='x';
    for(int i(1); i<n;++i)
        for(int j(1); j<n;++j){
            cin>>mas[i][j];
            cou[i][j]=0;
        };
    for(int i(1); i<n;++i)
        for(int j(1); j<n;++j){
            if(mas[i+1][j]=='o')
                ++cou[i][j];
            if(mas[i-1][j]=='o')
                ++cou[i][j];
            if(mas[i][j+1]=='o')
                ++cou[i][j];
            if(mas[i][j-1]=='o')
                ++cou[i][j];
            if(cou[i][j]&1){
                cout<<"NO";
                return 0;
            };
        };
    cout<<"YES";
    return 0;
}