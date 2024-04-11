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

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	return (x == 0)?y:gcd(y%x,x);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<long long,long long> > P(N+tisic,make_pair(0,0));
	for(int i =0; i < N; i++) cin >> P[i].ff >> P[i].ss;
	vector<dbl> pw2(N+tisic,1);
	for(int i =1; i <= N+patkan; i++) pw2[i] =pw2[i-1]/2;

	vector<dbl> S1x(N,0),S1y(N,0);
	for(int i =0; i < N; i++) {
		S1x[i] =((i == 0)?0:S1x[i-1])+pw2[i]*P[i].ff;
		S1y[i] =((i == 0)?0:S1y[i-1])+pw2[i]*P[i].ss;
	}

	dbl sumA =0;
	for(int i =0; i < N; i++) sumA +=S1y[i]*(P[i+2].ff-P[i+1].ff)*pw2[3];
	for(int i =0; i < N; i++) sumA -=S1x[i]*(P[i+2].ss-P[i+1].ss)*pw2[3];
	for(int i =1; i < N; i++) sumA +=S1y[i-1]*P[i].ff*pw2[2-i+N];
	for(int i =1; i < N; i++) sumA -=S1x[i-1]*P[i].ss*pw2[2-i+N];
	for(int i =2; i < N; i++) sumA +=P[i].ff*(P[i-1].ss-P[0].ss)*pw2[2+i];
	for(int i =2; i < N; i++) sumA -=P[i].ss*(P[i-1].ff-P[0].ff)*pw2[2+i];
	for(int i =1; i < N; i++) for(int k =i+1; k < min(i+120,N); k++)
		sumA +=(P[k].ss*P[i].ff-P[k].ff*P[i].ss)*pw2[2+k-i];

	dbl sumB =0;
	for(int i =0; i < N; i++) for(int j =i+1; j < min(N,i+80); j++) {
		// 1<<(j-i-1)-1 alebo 1<<(N-j+i-1)-1 polygonov
		long long b =gcd(abs(P[i].ff-P[j].ff),abs(P[i].ss-P[j].ss));
		sumB +=b*pw2[N+2-j+i]+b*pw2[2+j-i]-2*b*pw2[N+1];
		}
	for(int i =0; i < 80; i++) for(int j =i+80; j < N; j++) {
		// 1<<(j-i-1)-1 alebo 1<<(N-j+i-1)-1 polygonov
		long long b =gcd(abs(P[i].ff-P[j].ff),abs(P[i].ss-P[j].ss));
		sumB +=b*pw2[N+2-j+i]+b*pw2[2+j-i]-2*b*pw2[N+1];
		}

	dbl res =(sumA-sumB);
	res /=1-1.0*(1+N+1LL*N*(N-1)/2)*pw2[N];
	cout << res+1 << "\n";
	return 0;}

// look at my code
// my code is amazing