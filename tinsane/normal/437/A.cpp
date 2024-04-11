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
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double

// M_PI

//#pragma comment(linker, "/STACK:167772160")

/*
int compare (const void* a, const void* b){
    return ((*(pair<int, int>*)b).first-(*(pair<int, int>*)a).first);

}*/

/*
int compstr(const void* a, const void* b){
    if(*(string*)a>*(string*)b)
        return 1;
    else if(*(string*)a==*(string*)b)
        return 0;
    else
        return -1;
}
*/








int main(){
    //ios_base::sync_with_stdio(false);
    string a,b,c,d;
    int as,bs, cs,ds;
    int mas[4];
    mas[0]=0;
    mas[1]=0;
    mas[2]=0;
    mas[3]=0;
    cin>>a>>b>>c>>d;
    as=a.length()-2;
    bs=b.length()-2;
    cs=c.length()-2;
    ds=d.length()-2;
    if(((as*2<=bs) && (as*2<=cs) && (as*2<=ds))||((as>=bs*2) && (as>=cs*2) && (as>=ds*2)))
        mas[0]=1;
    if(((bs*2<=as) && (bs*2<=cs) && (bs*2<=ds))||((bs>=as*2) && (bs>=cs*2) && (bs>=ds*2)))
        mas[1]=1;
    if(((ds*2<=bs) && (ds*2<=cs) && (ds*2<=as))||((ds>=bs*2) && (ds>=cs*2) && (ds>=as*2)))
        mas[3]=1;
    if(((cs*2<=bs) && (cs*2<=ds) && (cs*2<=as))||((cs>=bs*2) && (cs>=ds*2) && (cs>=as*2)))
        mas[2]=1;
    if(mas[0]+mas[1]+mas[2]+mas[3]>1 || mas[0]+mas[1]+mas[2]+mas[3]==0)
        cout<<'C';
    else
        if(mas[0])
            cout<<'A';
        else
            if(mas[1]) cout<<'B';
            else if(mas[2]) cout<<'C';
            else cout<<'D';
    return 0;
}