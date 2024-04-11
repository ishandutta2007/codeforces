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

struct krt{
    int x, y, ax, ay;
};
krt mas[4];

int comp(const void*a, const void *b ){
    return (*(int*)a)-(*(int*)b);
}

bool ye(){
    int lol[6];
    lol[0]=(mas[0].x-mas[1].x)*(mas[0].x-mas[1].x)+(mas[0].y-mas[1].y)*(mas[0].y-mas[1].y);
    lol[1]=(mas[2].x-mas[1].x)*(mas[2].x-mas[1].x)+(mas[2].y-mas[1].y)*(mas[2].y-mas[1].y);
    lol[2]=(mas[3].x-mas[1].x)*(mas[3].x-mas[1].x)+(mas[3].y-mas[1].y)*(mas[3].y-mas[1].y);
    lol[3]=(mas[0].x-mas[2].x)*(mas[0].x-mas[2].x)+(mas[0].y-mas[2].y)*(mas[0].y-mas[2].y);
    lol[4]=(mas[0].x-mas[3].x)*(mas[0].x-mas[3].x)+(mas[0].y-mas[3].y)*(mas[0].y-mas[3].y);
    lol[5]=(mas[3].x-mas[2].x)*(mas[3].x-mas[2].x)+(mas[3].y-mas[2].y)*(mas[3].y-mas[2].y);
    qsort(lol, 6, sizeof(int), comp);
    if(lol[5]==lol[4] && lol[0]==lol[1] && lol[0]==lol[2] && lol[0]==lol[3] && lol[0]!=lol[4])
        return 1;
    return 0;
}

void mkst(int num){
    mas[num].x-=mas[num].ax;
    mas[num].y-=mas[num].ay;
    mas[num].y=-mas[num].y;
    swap(mas[num].y, mas[num].x);
    mas[num].y+=mas[num].ay;
    mas[num].x+=mas[num].ax;
}

int tryt(){
    int mi(MAXINT);
    for(int i(0);i<4;++i){
    for(int i1(0);i1<4;++i1){
    for(int i2(0);i2<4;++i2){
    for(int i3(0);i3<4;++i3){
        if(ye())
            mi=MIN(mi, (i1+i2+i3+i));
        mkst(3);
    }
        mkst(2);
    }
        mkst(1);
    }
        mkst(0);
    }
    if(mi==MAXINT)
        return -1;
    return mi;
}

int main(){
    int n;
    cin>>n;
    for(;n;--n){
        for(int i(0);i<4;++i)
            cin>>mas[i].x>>mas[i].y>>mas[i].ax>>mas[i].ay;
        cout<<tryt()<<'\n';
    }
    return 0;
}