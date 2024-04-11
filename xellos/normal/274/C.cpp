// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

struct pt {
	int x,y;
	};

int main() {
	int N;
	scanf(" %d",&N);
	vector<pt> P(N);
	for(int i =0; i < N; i++) scanf(" %d %d",&P[i].x,&P[i].y);

	dbl ans =0;
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) for(int k =j+1; k < N; k++) {
		long long Di =P[i].x*P[i].x+P[i].y*P[i].y, Dj =P[j].x*P[j].x+P[j].y*P[j].y, Dk =P[k].x*P[k].x+P[k].y*P[k].y;
		long long Dij =(P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y);
		long long Djk =(P[j].x-P[k].x)*(P[j].x-P[k].x)+(P[j].y-P[k].y)*(P[j].y-P[k].y);
		long long Dki =(P[k].x-P[i].x)*(P[k].x-P[i].x)+(P[k].y-P[i].y)*(P[k].y-P[i].y);
		if(Dij >= Djk+Dki || Djk >= Dij+Dki || Dki >= Dij+Djk) continue;
		long long D =2*(P[i].x*(P[j].y-P[k].y)+P[j].x*(P[k].y-P[i].y)+P[k].x*(P[i].y-P[j].y));
		dbl x =1.0*(Di*(P[j].y-P[k].y)+Dj*(P[k].y-P[i].y)+Dk*(P[i].y-P[j].y))/D;
		dbl y =-1.0*(Di*(P[j].x-P[k].x)+Dj*(P[k].x-P[i].x)+Dk*(P[i].x-P[j].x))/D;
		dbl r =sqrt((x-P[i].x)*(x-P[i].x)+(y-P[i].y)*(y-P[i].y));
		if(r < ans+soclose) continue;
		bool ok =true;
		for(int l =0; l < N; l++) {
			dbl d =sqrt((x-P[l].x)*(x-P[l].x)+(y-P[l].y)*(y-P[l].y));
			if(d < r-soclose) {ok =false; break;}
			}
		if(ok) ans =r;}

	for(int i =0; i < N; i++) for(int j =0; j < N; j++) for(int k =j+1; k < N; k++) if(i != j && i != k) {
		long long Dij =(P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y);
		long long Djk =(P[j].x-P[k].x)*(P[j].x-P[k].x)+(P[j].y-P[k].y)*(P[j].y-P[k].y);
		long long Dki =(P[k].x-P[i].x)*(P[k].x-P[i].x)+(P[k].y-P[i].y)*(P[k].y-P[i].y);
		if(Djk != Dij+Dki || Dij != Dki) continue;
		bool ok =false;
		for(int l =0; l < N; l++) {
			long long Dil =(P[i].x-P[l].x)*(P[i].x-P[l].x)+(P[i].y-P[l].y)*(P[i].y-P[l].y);
			long long Djl =(P[j].x-P[l].x)*(P[j].x-P[l].x)+(P[j].y-P[l].y)*(P[j].y-P[l].y);
			long long Dkl =(P[k].x-P[l].x)*(P[k].x-P[l].x)+(P[k].y-P[l].y)*(P[k].y-P[l].y);
			if(Dij == Djl && Dij == Dkl && Dil == Djk) {ok =true; break;}
			}
		dbl x =(P[j].x+P[k].x)/2.0, y =(P[j].y+P[k].y)/2.0;
		dbl r =sqrt((x-P[i].x)*(x-P[i].x)+(y-P[i].y)*(y-P[i].y));
		for(int l =0; l < N; l++) if(ok) {
			dbl d =sqrt((x-P[l].x)*(x-P[l].x)+(y-P[l].y)*(y-P[l].y));
			if(d < r-soclose) {ok =false; break;}
			}
		if(ok && r > ans) ans =r;}

	if(ans < soclose) printf("-1\n");
	else printf("%.10f\n",ans);
	return 0;}

// look at my code
// my code is amazing