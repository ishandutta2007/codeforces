#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,-N);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) T[i] =max(T[i],val);}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;}
	};

int main() {
	int N;
	scanf(" %d",&N);
	long long a,b,c,d;
	scanf(" %I64d/%I64d %I64d/%I64d",&b,&a,&d,&c);
	long long a2 =b, b2 =-a, c2 =d, d2 =-c;
	vector< pair<dbl,dbl> > V(N);
	map<dbl,int> Mx,My;
	Mx[0] =My[0] =0;
	for(int i =0; i < N; i++) {
		long long x,y;
		scanf(" %I64d %I64d",&x,&y);
		long long z =a*c2+b*d2;
		if(z == 0) V[i].ff =x;
		else {
			long long w =x*c2+y*d2;
			V[i].ff =1.0*w/z;}
		z =c*a2+d*b2;
		if(z == 0) V[i].ss =y;
		else {
			long long w =x*a2+y*b2;
			V[i].ss =1.0*w/z;}
		Mx[V[i].ff] =0;
		My[V[i].ss] =0;}

	int mx =0, my =0;
	ALL_THE(Mx,it) {
		if(it == Mx.begin()) it->ss =mx++;
		else {
			auto jt =it;
			jt--;
			if(abs(it->ff-jt->ff) < soclose) it->ss =mx;
			else it->ss =mx++;}
		}
	ALL_THE(My,it) {
		if(it == My.begin()) it->ss =my++;
		else {
			auto jt =it;
			jt--;
			if(abs(it->ff-jt->ff) < soclose) it->ss =my;
			else it->ss =my++;}
		}
	vector< pair<int,int> > Vi;
	for(int i =0; i < N; i++) {
		pair<int,int> p;
		auto it =Mx.lower_bound(V[i].ff-soclose);
		p.ff =it->ss;
		it =My.lower_bound(V[i].ss-soclose);
		p.ss =it->ss;
		if(p.ss > My[0] && p.ff > Mx[0]) Vi.push_back(p);}
	sort(begin(Vi),end(Vi));
	N =Vi.size();

	fin F(my);
	int j =0, ansF =0;
	vector<int> ans(N,0);
	F.put(My[0],0);
	for(int i =0; i < N; i++) {
		while(Vi[j].ff < Vi[i].ff) {
			F.put(Vi[j].ss,ans[j]);
			j++;}
		ans[i] =F.get(Vi[i].ss-1)+1;
		ansF =max(ansF,ans[i]);}

	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing