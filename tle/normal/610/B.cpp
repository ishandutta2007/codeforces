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
int n,a[233333];
bool ok[233333];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    int minn=2000000003,minm;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<minn) minn=a[i],minm=i;
    }
    for(int i=1;i<=n;i++) ok[i]=a[(i+minm-2+n)%n+1]>minn;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!ok[i]) continue;
        int tat;
        for(int j=i;j<=n;j++)
        {
            if(!ok[j]) break; else tat=j;
        }
        cnt=max(cnt,tat-i+1);
        i=tat;
    }
    cout<<((long long)n*minn+cnt);
    return 0;
}