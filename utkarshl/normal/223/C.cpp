#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
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
#define ul(x) scanf("%Lu",&x)
#define P 1000000007ull
ull pow(ull a,ull b){
	if(b==0)return 1;
	if(b==1)return a%P;
	ull x=pow((a*a)%P,b/2);
	if(b&1)x=(x*a)%P;
	return x%P;
}
int main()
{
	ui n,k;
	u(n),u(k);
	int inp[n];
	REP(i,n)
		i(inp[i]);
	ull ans[n];
	for(int i=0;i<n;i++)ans[i]=0;
	ull val=1;
	for(int i=0;i<n;i++){
		for(int t=0;i+t<n;t++){
			ans[t+i]=(ans[t+i]+(ull)inp[t]*val)%P;
		}
		val=((val*((ull)k+i))%P*pow(i+1,P-2))%P;
	}
	for(int i=0;i<n-1;i++)printf("%d ",(int)ans[i]);
	printf("%d",(int)ans[n-1]);
}