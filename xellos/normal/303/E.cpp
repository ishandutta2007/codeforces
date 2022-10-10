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
#define soclose 1e-6
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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	vector<int> L(N),R(N);
	set<int> x_posS;
	for(int i =0; i < N; i++) {
		scanf(" %d %d",&L[i],&R[i]);
		x_posS.insert(L[i]);
		x_posS.insert(R[i]);}
	vector<int> x_pos;
	ALL_THE(x_posS,it) x_pos.push_back(*it);

	vector< vector<dbl> > ans(N,vector<dbl>(N,0));

	vector<bool> bad(N,false);
	for(int x =1; x < (int)x_pos.size(); x++) {
		int st =0;
		for(int i =0; i < N; i++) {
			if(x_pos[x] <= L[i]) continue;
			if(x_pos[x-1] >= R[i]) {
				st++;
				continue;}
			}
		vector< vector<dbl> > p_akt(N+1-st,vector<dbl>(N+1-st,0));
		p_akt[0][0] =1;
		for(int i =0; i < N; i++) {
			if(x_pos[x] <= L[i]) continue;
			if(x_pos[x-1] >= R[i]) continue;
			dbl p_lt =1.0*(x_pos[x-1]-L[i])/(R[i]-L[i]);
			dbl p_eq =1.0*(x_pos[x]-x_pos[x-1])/(R[i]-L[i]);
			dbl p3 =1.0*(R[i]-x_pos[x])/(R[i]-L[i]);

			for(int j =N-st; j >= 0; j--) for(int k =N-st-j; k >= 0; k--)
				p_akt[j][k] =((j == 0)?0:p_akt[j-1][k])*p_lt+((k == 0)?0:p_akt[j][k-1])*p_eq+p_akt[j][k]*p3;
			}

		for(int i =0; i < N; i++) if(!bad[i]) {
			if(x_pos[x] <= L[i] || x_pos[x-1] >= R[i]) continue;
			dbl p_lt =1.0*(x_pos[x-1]-L[i])/(R[i]-L[i]);
			dbl p_eq =1.0*(x_pos[x]-x_pos[x-1])/(R[i]-L[i]);
			dbl p3 =1.0*(R[i]-x_pos[x])/(R[i]-L[i]);
			vector< vector<dbl> > akt(N-st,vector<dbl>(N-st,0));
			if(p3 > p_lt && p3 > p_eq) {
				for(int j =0; j < N-st; j++) for(int k =0; k < N-st-j; k++)
					akt[j][k] =(p_akt[j][k]-((k == 0)?0:akt[j][k-1])*p_eq-((j == 0)?0:akt[j-1][k])*p_lt)/p3;
				}
			else if(p_eq > p_lt) {
				for(int k =N-st-1; k >= 0; k--) for(int j =0; j < N-st-k; j++)
					akt[j][k] =(p_akt[j][k+1]-((k == N-1-st)?0:(akt[j][k+1]*p3+((j == 0)?0:akt[j-1][k+1])*p_lt)))/p_eq;
				}
			else {
				for(int j =N-st-1; j >= 0; j--) for(int k =0; k < N-st-j; k++)
					akt[j][k] =(p_akt[j+1][k]-((j == N-1-st)?0:(akt[j+1][k]*p3+((k == 0)?0:akt[j+1][k-1])*p_eq)))/p_lt;
				}
			vector<dbl> add(N+1,0);
			for(int j =0; j < N-st; j++) for(int k =0; k < N-st-j; k++) {
				if(akt[j][k] > 1.1) bad[i] =true;
				add[st+j] +=akt[j][k]/(k+1)*p_eq;
				add[st+j+k+1] -=akt[j][k]/(k+1)*p_eq;}
			dbl s2 =0;
			for(int j =0; j < N; j++) {
				s2 +=add[j];
				ans[i][j] +=s2;}
			}
		}
	for(int i =0; i < N; i++) {
		dbl sump =0;
		for(int j =0; j < N; j++) sump +=ans[i][j];
		if(abs(sump-1) > soclose) bad[i] =true;}

	for(int b =0; b < N; b++) if(bad[b]) {
		for(int j =0; j < N; j++) ans[b][j] =0;	
		for(int x =1; x < (int)x_pos.size(); x++) if(x_pos[x] <= R[b] && x_pos[x-1] >= L[b]) {
			int st =0;
			for(int i =0; i < N; i++) if(i != b) {
				if(x_pos[x] <= L[i]) continue;
				if(x_pos[x-1] >= R[i]) {
					st++;
					continue;}
				}
			vector< vector<dbl> > p_akt(N+1-st,vector<dbl>(N+1-st,0));
			p_akt[0][0] =1;
			for(int i =0; i < N; i++) if(i != b) {
				if(x_pos[x] <= L[i]) continue;
				if(x_pos[x-1] >= R[i]) continue;
				dbl p_lt =1.0*(x_pos[x-1]-L[i])/(R[i]-L[i]);
				dbl p_eq =1.0*(x_pos[x]-x_pos[x-1])/(R[i]-L[i]);
				dbl p3 =1.0*(R[i]-x_pos[x])/(R[i]-L[i]);

				for(int j =N-st; j >= 0; j--) for(int k =N-st-j; k >= 0; k--)
					p_akt[j][k] =((j == 0)?0:p_akt[j-1][k])*p_lt+((k == 0)?0:p_akt[j][k-1])*p_eq+p_akt[j][k]*p3;
				}

			dbl p_eq =1.0*(x_pos[x]-x_pos[x-1])/(R[b]-L[b]);
			vector<dbl> add(N+1,0);
			for(int j =0; j < N-st; j++) for(int k =0; k < N-st-j; k++) {
				add[st+j] +=p_akt[j][k]/(k+1)*p_eq;
				add[st+j+k+1] -=p_akt[j][k]/(k+1)*p_eq;}
			dbl s2 =0;
			for(int j =0; j < N; j++) {
				s2 +=add[j];
				ans[b][j] +=s2;}
			}
		}

	for(int i =0; i < N; i++) {
		for(int j =0; j < N; j++) {
			if(j > 0) printf(" ");
			printf("%.12lf",(double)abs(ans[i][j]));}
		printf("\n");}

	// palindromic tree is better than splay tree!
	return 0;}

// look at my code
// my code is amazing