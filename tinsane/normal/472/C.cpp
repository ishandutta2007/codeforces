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
    int n, mas[100000];
    bool ye(1);
    string nam[100000], sec[100000], now("");
    cin>>n;
    for(int i(0);i<n;++i)
        cin>>nam[i]>>sec[i];
    for(int i(0);i<n;++i){
        cin>>mas[i];
        --mas[i];
    }
    now=MIN(nam[mas[0]], sec[mas[0]]);
    for(int i(1);i<n;++i){
        if(nam[mas[i]]>sec[mas[i]]){
            if(now>sec[mas[i]])
                if(now>nam[mas[i]]){
                    ye=0;
                    break;
                }
                else
                    now=nam[mas[i]];
            else
                now=sec[mas[i]];
        }
        else{
            if(now>nam[mas[i]])
                if(now>sec[mas[i]]){
                    ye=0;
                    break;
                }
                else
                    now=sec[mas[i]];
            else
                now=nam[mas[i]];
        }
    }
    if(ye)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}