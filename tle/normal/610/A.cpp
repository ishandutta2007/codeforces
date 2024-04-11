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
//
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("0\n");
        return 0;
    }
    int g=n/2/2;
    if((n/2)%2==0) --g;
    printf("%d\n",g);
    return 0;
}