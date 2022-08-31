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
#define l(x) scanf("%Ld",&x)
#define ul(x) scanf("%Lu",&x)
#include"stack"
struct sym{
	char symbol;
	int pos,count;
};
int main(){
	char inp[2000000];
	scanf("%s",inp);
	int n=strlen(inp);
	assert(n<=100000 && inp[n]==0);
	stack<sym> s;
	int bestans=0;
	int besti=0,bestj=-1;
	int count[n+100];
	count[0]=0;
	int lastvalid=-1,lastcount=0;
	for(int i=0;i<n;i++){
	 	count[i+1]=count[i]+((inp[i]=='[')?1:0);
		sym symbol;
		symbol.symbol=inp[i];
		symbol.pos=i;
		symbol.count=count[i+1];
		if(inp[i]=='('||inp[i]=='[')
			s.push(symbol);
		else{
			if(!s.empty() && abs(s.top().symbol-inp[i])<=4)
			{
				s.pop();
				int cnt=count[i]-lastcount,i0=lastvalid+1;
				if(!s.empty())
					cnt=count[i]-s.top().count,
					i0=s.top().pos+1;
				if(bestans<cnt){
					bestans=cnt;
					bestj=i;
					besti=i0;
				}
			}
			else{
				while(!s.empty())s.pop();
				lastvalid=i;
				lastcount=count[i+1];
			}
		}
	}
	inp[bestj+1]=0;
	assert((bestj-besti+1)%2==0);
	printf("%d\n",bestans);
	printf("%s",inp+besti);
}