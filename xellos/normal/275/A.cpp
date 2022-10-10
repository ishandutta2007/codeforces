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

int main() {
	int dx[] ={0,1,-1,0,0};
	int dy[] ={0,0,0,1,-1};
	int st[][3] ={{1,1,1},{1,1,1},{1,1,1}};
	for(int i =0; i < 3; i++) for(int j =0; j < 3; j++) {
		int a;
		scanf(" %d",&a);
		if(a%2 != 0) for(int k =0; k < 5; k++)
			if(i+dx[k] >= 0 && i+dx[k] < 3 && j+dy[k] >= 0 && j+dy[k] < 3)
				st[i+dx[k]][j+dy[k]] =1-st[i+dx[k]][j+dy[k]];
		}
	for(int i =0; i < 3; i++) {
		for(int j =0; j < 3; j++) printf("%d",st[i][j]);
		printf("\n");}
	return 0;}

// look at my code
// my code is amazing