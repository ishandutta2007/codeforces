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
    int n,m,k, ans(0);
    ll mas[1000], fed;
    cin>>n>>m>>k;
    for(int i(0);i<m;++i)
        cin>>mas[i];
    cin>>fed;
    for(int i(0);i<m;++i){
        mas[i]^=fed;
        int cou(0);
        for(;mas[i];mas[i]>>=1)
            if(mas[i]&1)
                ++cou;
        if(cou<=k)
            ++ans;
    }
    cout<<ans;
    return 0;
}