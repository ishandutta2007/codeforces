#include <cmath>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
double a,b,c;
struct P{
	int on = 0;
	double x,y;
	P operator - (P p){
		P n;
       	n.x = x-p.x;n.y = y-p.y;
       	return n;
    }
	double dist(){
		return sqrt(x*x+y*y);
	}
}alp[10];
double dist[20] = {0,1e18,1e18,1e18,1e18,1e18,1e18,1e18,1e18,1e18,1e18};
int main() {
	cout<<setprecision(15)<<fixed;
	cin>>a>>b>>c>>alp[0].x>>alp[0].y>>alp[1].x>>alp[1].y;
	alp[0].on = alp[1].on = 1;
	double ans = abs(alp[0].x-alp[1].x)+abs(alp[1].y-alp[0].y);
	if(!a || !b){
		cout<<ans<<endl;
		return 0;
	}
	alp[2].x = alp[0].x;alp[2].y = (a*alp[2].x+c)/(-b);
	alp[3].x = alp[1].x;alp[3].y = (a*alp[3].x+c)/(-b);
	alp[4].y = alp[0].y;alp[4].x = (b*alp[4].y+c)/(-a);
	alp[5].y = alp[1].y;alp[5].x = (b*alp[5].y+c)/(-a);
	for(int i=0;i<20;i++){
		for(int a=0;a<6;a++){
			for(int b=0;b<6;b++){
				if((alp[a].on == 0 && alp[b].on == 0) || alp[a].x == alp[b].x || alp[a].y == alp[b].y)dist[b] = min(dist[a]+(alp[b]-alp[a]).dist(),dist[b]);
			}
		}
	}
	
	cout<<min(dist[1],ans)<<endl;
	return 0;
}