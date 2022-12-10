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
int n, mas[100000], m, x;

int bins(int num, int beg, int end){
    if(end==beg)
        return beg;
    if(end==beg+1)
        if(mas[beg]>=num)
            return beg;
        else
            return end;
    int mid((beg+end)>>1);
    if(mas[mid]>=num)
        return bins(num, beg, mid);
    else
        return bins(num, mid, end);
}

int main(){
    cin>>n;
    cin>>mas[0];
    for(int i(1);i<n;++i){
        cin>>mas[i];
        mas[i]+=mas[i-1];
    }
    cin>>m;
    for(int i(0);i<m;++i){
        cin>>x;
        cout<<bins(x, 0, n)+1<<'\n';
    }
    return 0;
}