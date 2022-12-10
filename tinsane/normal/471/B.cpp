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
    return ((PII*)a)->first-((PII*)b)->first;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, pcou(0), r(0);
    int cou[2001];
    PII mas[2000];
    cin>>n;
    for(int i(0);i<2001;++i)
        cou[i]=0;
    for(int i(0);i<n;++i){
        cin>>mas[i].first;
        ++cou[mas[i].first];
        mas[i].second=i+1;
    }
    qsort(mas, n, sizeof(PII), comp);
    for(;r<2001;++r){
        if(cou[r]>=3){
            pcou=100000;
            break;
        }
        if(cou[r]==2)
            ++pcou;
    }
    if(pcou<2){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    if(pcou==100000){
        for(int i(0);i<n;++i)
            cout<<mas[i].second<<' ';
        cout<<'\n';
        int i(0);
        for(;mas[i].first<r;++i)
            cout<<mas[i].second<<' ';
        cout<<mas[i+1].second<<' ';
        cout<<mas[i].second<<' ';
        i+=2;
        for(;i<n;++i)
            cout<<mas[i].second<<' ';
        i=0;
        cout<<'\n';
        for(;mas[i].first<r;++i)
            cout<<mas[i].second<<' ';
        cout<<mas[i+2].second<<' ';
        cout<<mas[i].second<<' ';
        cout<<mas[i+1].second<<' ';
        i+=3;
        for(;i<n;++i)
            cout<<mas[i].second<<' ';
        return 0;
    }
    for(int i(0);i<n;++i)
        cout<<mas[i].second<<' ';
    cout<<'\n';
    int i(0);
    for(;mas[i].first!=mas[i+1].first;++i)
        cout<<mas[i].second<<' ';
    cout<<mas[i+1].second<<' ';
    cout<<mas[i].second<<' ';
    i+=2;
    for(;i<n;++i)
        cout<<mas[i].second<<' ';
    i=0;
    cout<<'\n';
    for(;mas[i].first!=mas[i+1].first;++i)
        cout<<mas[i].second<<' ';
    cout<<mas[i].second<<' ';
    ++i;
    for(;mas[i].first!=mas[i+1].first;++i)
        cout<<mas[i].second<<' ';
    cout<<mas[i+1].second<<' ';
    cout<<mas[i].second<<' ';
    i+=2;
    for(;i<n;++i)
        cout<<mas[i].second<<' ';
    return 0;
}