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
struct str{
	int val,i,j;
	bool operator<(const str s)const{
		return val<s.val;
	}
};
int main(){
	ui n;
	u(n);
	int c[n],sum=0;
	REP(i,n){
		i(c[i]);
		sum+=c[i];
	}
	str s[sum];
	int l=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<c[i];j++){
			i(s[l].val);
			s[l].i=i,s[l].j=j;
			l++;
		}
	vector<pair<str,str> > p;
	for(int i=0;i<sum;i++){
		if(s[i].val==i+1)continue;
		int j=s[i].val-1;
		do{
			p.push_back(make_pair(s[i],s[j]));
			swap(s[i].val,s[j].val);
			j=s[i].val-1;
		}while(j!=i);
	}
	printf("%d\n",p.size());
	FOREACH(it,p){
		printf("%d %d %d %d\n",it->first.i+1,it->first.j+1,(it->second).i+1,it->second.j+1);
	}
}