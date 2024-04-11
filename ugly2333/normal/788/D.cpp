//CF 788D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int W = 1e8;
const int E = -3355336;
const int O = 1024;
vector<int> vx,vy;
int Q(int x,int y){
	int z;
	printf("0 %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&z);
	return z;
}
void solve(int u){
	if(u>W)
		return;
	int z=Q(u,u);
	if(!z){
		if(!Q(u,E))
			vx.push_back(u);
		if(!Q(E,u))
			vy.push_back(u);
		if(u+O<=W){
			if(Q(u+O,u+O)==O)
				solve(u+O);
			else
				solve(u+1);
		}
		else
			solve(u+1);
	}
	else
		solve(u+z);
}
int main()
{
	int i;
	solve(-W);
	printf("1 %d %d\n",vx.size(),vy.size());
	for(i=vx.size();i--;)
		printf("%d ",vx[i]);
	printf("\n");
	for(i=vy.size();i--;)
		printf("%d ",vy[i]);
	return 0;
}