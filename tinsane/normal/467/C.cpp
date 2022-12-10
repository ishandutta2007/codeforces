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

ll dp[5001][5001];

int main(){
    ll n,m,k, mas[5000], ma;        //dp[k][n]
    cin>>n>>m>>k;
    for(int i(0);i<n;++i)
        cin>>mas[i];
    for(int j(m);j<n;++j)
        dp[0][j]=0;
    ++k;
    for(int i(1);i<k;++i){
        ma=0;
        ll cou(0);
        for(int j(m*(i-1)-1);j<m*i-1;++j)
            cou+=mas[j];
        for(int j(m*i);j<=n;++j){
            cou-=mas[j-m-1]-mas[j-1];
            ma=MAX(ma, dp[i-1][j-m]);
            dp[i][j]=cou+ma;
        }
    }
    ma=0;
    for(int i(0);i<=n;++i)
        ma=MAX(ma, dp[k-1][i]);
    cout<<ma;
    return 0;
}