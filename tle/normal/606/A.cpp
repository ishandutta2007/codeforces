//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define fos (feof(stdin))
typedef long double ld;
typedef long long ll;
double PI=asin(1)*2;
void swap(int& a,int& b) {a^=b; b^=a; a^=b;}
void swap(ll& a,ll& b) {a^=b; b^=a; a^=b;}
void swap(bool& a,bool& b) {if(a!=b) {a^=1; b^=1;}}
template <class T>
T* fnew(int siz) //TPOD 
{
    T* p=(T*)malloc(sizeof(T)*siz);
    memset(p,0,sizeof(T)*siz);
    return p;
}
#ifndef BUFSIZE
#define BUFSIZE 100000
#endif
//
int a,b,c,x,y,z;
int main()
{
    cin>>a>>b>>c>>x>>y>>z;
    int ga=0,gb=0,gc=0,xy=0;
    if(a>=x) ga+=a-x; else xy+=x-a;
    if(b>=y) gb+=b-y; else xy+=y-b;
    if(c>=z) gc+=c-z; else xy+=z-c;
    if(ga/2+gb/2+gc/2>=xy) printf("Yes\n"); else printf("No\n");
    return 0;
}