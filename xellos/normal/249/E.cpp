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

typedef unsigned long long ull;

ull mod0 =10000000000LL, mod1 =10000000001LL, mod;

ull sum1(ull a, ull b) {
	// sum k
	ull v =b, w =b+1, x =a, y =(a == 0)?0:(a-1);
	if(v%2 == 0) v /=2;
	else w /=2;
	if(x%2 == 0) x /=2;
	else y /=2;
	long long ret =(v*w+(mod-x)*y)%mod;
	return ret%mod;}

ull sum2(ull a, ull b) {
	// sum k**2
	ull v =b, w =b+1, u =2*b+1, p =a, r =(a == 0)?0:(a-1), s =(a == 0)?0:(2*a-1);
	if(v%2 == 0) v /=2;
	else w /=2;
	if(p%2 == 0) p /=2;
	else r /=2;
	if(v%3 == 0) v /=3;
	else if(w%3 == 0) w /=3;
	else u /=3;
	if(p%3 == 0) p /=3;
	else if(r%3 == 0) r /=3;
	else s /=3;
	ull l =((v*u)%mod*w)%mod+mod-((p*s)%mod*r)%mod;
	return l%mod;}

ull sumUp(ull x1, ull x2, ull y1, ull y2) {
	// [x1..x2] rastuce vzdy o 1
	// sum (y*y+x1..y*y+1+x2] = (y*y+1+x2)*(y*y+2+x2)-(y*y+x1)*(y*y+1+x1)
	ull ret =((1+x2-x1)*sum2(y1,y2))%mod;
//	for(long long y =y1; y <= y2; y++) ret +=((y*y+1+x2)*(y*y+2+x2)-(y*y+x1)*(y*y+1+x1))/2;
	ull v =y2+1-y1, w =x2*x2+2+3*x2+2*mod-x1-x1*x1;
	if(v%2 == 0) v /=2;
	else w /=2;
	w %=mod;
	v %=mod;
	// sum (x2**2+2+3*x2-x1-x1**2)/2+(1+x2-x1)*y**2
	return (ret+v*w)%mod;}

ull sumDn(ull x1, ull x2, ull y1, ull y2) {
	// [y1..y2] klesajuce vzdy o 1
	// (x+1)*(x+1)-[y1..y2],  sum [(x+1)*(x+1)-y2..(x+1)*(x+1)-y1] = (((x+1)*(x+1)-y1)*((x+1)*(x+1)-y1+1)-((x+1)*(x+1)-y2)*((x+1)*(x+1)-y2-1))/2
	ull ret =((1+y2-y1)*sum2(x1+1,x2+1))%mod;
//	for(long long x =x1+1; x <= x2+1; x++) ret +=((x*x-y1)*(x*x-y1+1)-(x*x-y2)*(x*x-y2-1))/2;
	// sum (y1**2-y1-y2**2-y2)/2+(1+y2-y1)*x**2
	ull v =1+x2-x1, w =y1+y2, u =y2+1-y1;
	if(v%2 == 0) v /=2;
	else if(w%2 == 0) w /=2;
	else u /=2;
	w =(w*u)%mod;
	return (ret+v*(mod-w))%mod;}

ull sumUhl(ull a, ull b) {
	// [a..b]
	// 1..(b+1)*(b+1)
	ull v =((b+1)*(b+1)+1), u =b+1, w =(a*a+1), p =a;
	if(v%2 == 0) v /=2;
	else u /=2;
	if(w%2 == 0) w /=2;
	else p /=2;
	v %=mod;
	w %=mod;
	ull ret =((v*u)%mod*(b+1))%mod+mod-((w*p)%mod*a)%mod;
	return (ret+2*mod-sumUp(0,a-1,a,b)-sumDn(a,b,0,a-1))%mod;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		ull x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;

		if(x2 <= y1) {
			mod =mod0;
			ull ans =sumUp(x1,x2,y1,y2)%mod;
			mod =mod1;
			ull ans2 =sumUp(x1,x2,y1,y2)%mod;
			if(ans != ans2) {
				cout << "...";
				int p =0; ans2 =ans;
				while(ans2 > 0) {p++; ans2 /=10;}
				for(int j =0; j < 10-p; j++) cout << "0";}
			cout << ans << "\n";
			continue;}
		if(y2 <= x1) {
			mod =mod0;
			ull ans =sumDn(x1,x2,y1,y2)%mod;
			mod =mod1;
			ull ans2 =sumDn(x1,x2,y1,y2)%mod;
			if(ans != ans2) {
				cout << "...";
				int p =0; ans2 =ans;
				while(ans2 > 0) {p++; ans2 /=10;}
				for(int j =0; j < 10-p; j++) cout << "0";}
			cout << ans << "\n";
			continue;}

		mod =mod0;
		ull ans =0;
		ull x01 =x1, x02 =x2, y01 =y1, y02 =y2;
		if(y2 > x2) {
			ans +=sumUp(x1,x2,x2+1,y2);
			y2 =x2;}
		else if(y2 < x2) {
			ans +=sumDn(y2+1,x2,y1,y2);
			x2 =y2;}

		if(y1 < x1) {
			ans +=sumDn(x1,x2,y1,x1-1);
			y1 =x1;}
		else if(y1 > x1) {
			ans +=sumUp(x1,y1-1,y1,y2);
			x1 =y1;}

		ans +=sumUhl(x1,x2);
		ans %=mod;

		mod =mod1;
		ull ans2 =0;
		x1 =x01, x2 =x02, y1 =y01, y2 =y02;
		if(y2 > x2) {
			ans2 +=sumUp(x1,x2,x2+1,y2);
			y2 =x2;}
		else if(y2 < x2) {
			ans2 +=sumDn(y2+1,x2,y1,y2);
			x2 =y2;}

		if(y1 < x1) {
			ans2 +=sumDn(x1,x2,y1,x1-1);
			y1 =x1;}
		else if(y1 > x1) {
			ans2 +=sumUp(x1,y1-1,y1,y2);
			x1 =y1;}

		ans2 +=sumUhl(x1,x2);
		ans2 %=mod;

		if(ans != ans2) {
			cout << "...";
			int p =0; ans2 =ans;
			while(ans2 > 0) {p++; ans2 /=10;}
			for(int j =0; j < 10-p; j++) cout << "0";}
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing