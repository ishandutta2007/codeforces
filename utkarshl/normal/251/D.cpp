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
#include"bitset"
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
#define l(x) scanf("%I64d",&x)
int main(){
	ui n;
	u(n);
	ull inp[n];
	ull totalxor=0,s2xor=0;
	REP(i,n)
		l(inp[i]),
		totalxor^=inp[i];
	assert(n<=100000);
	vector<bitset<100001> > b;
	vector<int> postn;
	set<int> finalsoln;
	vector<ui> vecc;
	for(ui x=62;x<64;x--)
		if((totalxor&(1ull<<x))==0)vecc.push_back(x);
	for(ui x=62;x<64;x--)
		if(totalxor&(1ull<<x))vecc.push_back(x);
	FOREACH(it,vecc){
		ui x=*it;
		bitset<100001> b1;
		b1.reset();
		REP(i,n)if(inp[i]&(1ull<<x))b1.set(i);
		b1.set(n);
		REP(i,postn.size())if(b1[postn[i]])b1^=b[i];
		int pos=-1;
		REP(i,n)if(b1[i]){pos=i;  break;}
		if(pos!=-1){
			FOREACH(y,b)
				if((*y)[pos])(*y)^=b1;
			postn.push_back(pos);
			b.push_back(b1);
			s2xor|=(1ull<<x);
		}
		if(b1[n]==0)s2xor|=(1ull<<x);
	}
	REP(x,b.size())
		if(b[x][n])
			finalsoln.insert(postn[x]);
//	printf("%Ld\n",s2xor+(totalxor^s2xor));
	REP(i,n)printf("%d ",finalsoln.count(i)+1);
}