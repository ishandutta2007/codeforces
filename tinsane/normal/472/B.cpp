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

int comp(const void* a, const void* b){
    return (*((int *)a))-(*((int *)b));
}

int main(){
    ios_base::sync_with_stdio(0);
    int n,k, mas[2000], ans(0);
    cin>>n>>k;
    for(int i(0);i<n;++i){
        cin>>mas[i];
        --mas[i];
    }
    qsort(mas, n, sizeof(int), comp);
    for(int i(n-1);i>=0;i-=k)
        ans+=mas[i]*2;
    cout<<ans;
    return 0;
}