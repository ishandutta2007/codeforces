// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int R,H;
	cin >> R >> H;
	int ans =2*(int)floor((double)(H+(double)R/2.0)/R);
	for(int i =1; i <= H+1; i++) {
		// i poschodi s balonom v strede, potom max. poschodi bez toho
		double hRem =H-sqrt(3)/2*(2*i-1)*R;
		int akt =i*3+2*(int)floor(hRem/R);
		if(hRem > 0) ans =max(ans,akt);
		// na vrchu su len 4
		hRem =H-(double)R/2.0-sqrt(3)*i*R;
		if(hRem > 0) ans =max(ans,2*(i+1)+i+2*(int)floor(hRem/R));}
	cout << max(1,ans) << "\n";
    return 0;}
        
// look at my code
// my code is amazing