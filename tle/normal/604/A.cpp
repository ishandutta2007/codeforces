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
namespace fib {char b[BUFSIZE]={},*f=b;}
#define gc ((*fib::f)?(*(fib::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
inline const int& ri(int& x)
{
	int tmp=0; bool fu=0; char s;
	while(s=gc,s!='-'&&(s<'0'||s>'9')) ;
	if(s=='-') fu=1; else tmp=s-'0';
	while(s=gc,s>='0'&&s<='9') tmp=tmp*10+s-'0';
	if(fu) return x=-tmp; else return x=tmp;
}
inline int _gi() {int p; ri(p); return p;}
#define gi _gi()
struct _fin {} fsin;
const _fin& operator >> (const _fin& s,char& p) {p=gc; return s;}
const _fin& operator >> (const _fin& s,int& p) {ri(p); return s;}
#define FO(s) {freopen(#s".in","r",stdin);freopen(#s".out","w",stdout);}
//
int m1,m2,m3,m4,m5,w1,w2,w3,w4,w5,hs,hu;
double gm(int x,int m,int w)
{
	return max(0.3*x,(1-m/250.0)*x-50*w);
}
int main()
{
	cin>>m1>>m2>>m3>>m4>>m5>>w1>>w2>>w3>>w4>>w5>>hs>>hu;
	double ans=0;
	ans+=gm(500,m1,w1);
	ans+=gm(1000,m2,w2);
	ans+=gm(1500,m3,w3);
	ans+=gm(2000,m4,w4);
	ans+=gm(2500,m5,w5);
	ans+=hs*100-hu*50;
	printf("%d\n",int(ans+1e-6));
	return 0;
}