#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& ci;
typedef const unsigned int& cui;
typedef const long long& cll;
typedef const unsigned long long& cull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%l64d",&x)
#define ul(x) scanf("%l64u",&x)
int main()
{
	ui n;
	u(n);
	if(n%2==0)printf("-1\n");
	else {
		for(int i = 0; i<n; i++) printf("%d ", i);
		printf("\n");
		for(int i = 0; i<n; i++) printf("%d ", i);
		printf("\n");
		for(int i = 0; i<n; i++) printf("%d ", (2*i)%n);
		printf("\n");
	}
}