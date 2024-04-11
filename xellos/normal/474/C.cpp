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
#define param vector<int>
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int xr[4], yr[4], hx[4], hy[4];
		for(int i =0; i < 4; i++) {
			cin >> xr[i] >> yr[i] >> hx[i] >> hy[i];
			xr[i] -=hx[i];
			yr[i] -=hy[i];}
		int a[4];
		int ans =-1;
		for(a[0] =0; a[0] < 4; a[0]++) for(a[1] =0; a[1] < 4; a[1]++) 
			for(a[2] =0; a[2] < 4; a[2]++) for(a[3] =0; a[3] < 4; a[3]++) {
				int akt =a[0]+a[1]+a[2]+a[3];
				vector< pair<int,int> > p(4);
				for(int i =0; i < 4; i++) p[i].ff =xr[i], p[i].ss =yr[i];
				for(int i =0; i < 4; i++) for(int j =0; j < a[i]; j++) {
					int x2 =-p[i].ss, y2 =p[i].ff;
					p[i].ff =x2;
					p[i].ss =y2;}
				for(int i =0; i < 4; i++) p[i].ff +=hx[i], p[i].ss +=hy[i];
				bool isSq =false;
				vector<int> per(4);
				for(int i =0; i < 4; i++) per[i] =i;
				while(true) {
					bool canSq =true;
					int d =(p[per[0]].ff-p[per[1]].ff)*(p[per[0]].ff-p[per[1]].ff)+(p[per[0]].ss-p[per[1]].ss)*(p[per[0]].ss-p[per[1]].ss);
					if(d == 0) canSq =false;
					for(int i =0; i < 4; i++) {
						if((p[per[i]].ff-p[per[(i+1)%4]].ff)*(p[per[i]].ff-p[per[(i+1)%4]].ff)+(p[per[i]].ss-p[per[(i+1)%4]].ss)*(p[per[i]].ss-p[per[(i+1)%4]].ss) != d)
							canSq =false;
						if((p[per[(i+1)%4]].ff-p[per[i]].ff)*(p[per[(i+1)%4]].ff-p[per[(i+2)%4]].ff)+(p[per[(i+1)%4]].ss-p[per[i]].ss)*(p[per[(i+1)%4]].ss-p[per[(i+2)%4]].ss) != 0)
							canSq =false;
						}
					if(canSq) {isSq =true; break;}
					if(!next_permutation(per.begin(),per.end())) break;}
				if(isSq) {
					if(ans == -1) ans =akt;
					else ans =min(ans,akt);}
				}
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing