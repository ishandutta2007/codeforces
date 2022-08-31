#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
#define p printf
void cpy(char d) {p("10%ct",d);}
void ncpy(char d) {p("01%ct",d);}
void mand_(int x)
{
	p("rrrr%d" //choose spot
	"rrrr0llll" //put mark
	"lllltt%d" //work
	"rrrrtrtrtrtrtrt" //back mark
	"rellll" //back spot
	"lelelelerrrr" //clean
	,x,!x);
}
void mand() {return mand_(0);}
void nand() {return mand_(1);}
const int S=34;
void fillS()
{
	p("r"); for(int i=1;i<=S;++i) p("l"); p("0");
	for(int i=1;i<=S+1;++i) p("srt");
	for(int i=1;i<=S+1;++i) p("0slt");
	p("l"); for(int i=1;i<=S-1;++i) p("r");
}
char op[2333];
void mv(string s,int r=1)
{
	int n=s.size();
	for(int i=0;i<n;++i)
		p("%c",s[i]),cpy(op[s[i]]);
	for(int i=n-1;i>=r;--i)
		p("%ce",op[s[i]]);
	for(int i=r;i<=n-1;++i)
		p("%c",s[i]);
	//move to that target, erase path
}
void mxor()
{
	p("r");
	mv("rd");
	p("ll");
	cpy('u');
	nand();
	mv("u",0);
	p("ll");
	ncpy('l');
	mv("d");
	p("ll");
	ncpy('u');
	nand();
	mv("llll",0);
	p("rrrru");
	mv("dll",0);
	p("ll");
	mand();
	mv("lllurll",0);
}
int main()
{
	op['r']='l';
	op['l']='r';
	op['u']='d';
	op['d']='u';
	fillS(); p("u"); fillS();
	p("r0l");
	for(int i=1;i<=32;++i)//31;++i)
	{
		mv("uu");
		p("ddr");
		mv("uu");
		p("l");
//		puts("");
		mxor();
//		puts("");
		p("ddd");
		mv("rruuul");
		mv("u"); p("d");
		p("l");
//		puts("");
		mxor();
		mv("uu",0);
		p("dddd");
		mv("u");
		p("dr");
		mv("ur");
		p("ll");
		nand();
//		puts("");
		mv("u");
		p("lllu");
		mv("ddr");
		p("lld");
		mv("u");
//		puts("");
		nand();
//		puts("");
		mv("lu");
		p("llu");
		mv("ddr");
		p("ld");
		mv("ul");
//		puts("");
		nand();
//		puts("");
		mv("ll",0);
		p("ur");
		mv("llld",0);
		mand();
		mv("ll",0);
		p("urr");
		mv("lllld",0);
		mand();
		p("l"); ncpy('r');
		mv("llld"); p("l");
		//cleanup
		p("r");
		mv("druurrrllluudddl");
		p("l");
	}
	p("uuuu");
	for(int i=1;i<=S+4;++i)
		p("rst");
	p("r");
	puts("");
	return 0;
}