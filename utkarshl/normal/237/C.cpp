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
int primes[1000001];
bool sv[1000001]={0};
int main(){
	int a,b,k;
	i(a),i(b),i(k);
	for(int i=2;i*i<=b;i++)
		if(sv[i]==0)
			for(int j=i*i;j<=b;j+=i)
				sv[j]=1;
	int idx=0;
	for(int i=a;i<=b;i++)if(sv[i]==0&&i>1)primes[idx++]=i;
	if(k>idx)printf("-1");
	else{
		int ans=primes[k-1]-a+1,i=0;
		while(i+k<idx){
			ans=max(ans,primes[i+k]-primes[i]);
			i++;
		}
		ans=max(ans,b+1-primes[idx-k]);
		printf("%d",ans);
	}
}