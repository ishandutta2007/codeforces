//CF 930D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 444444;
const int H = 222222;
const int W = 100002;
int n,l[N][2],r[N][2];
vector<int> v[N][2];
int main()
{
	int i,j,k,x,y;
	LL ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		x+=W,y+=W;
		v[x+y][(x^y)&1].push_back(x-y+H);
	}
	for(k=0;k<2;k=k+1){
		l[0][0]=N,r[0][0]=0;
		for(i=1;i<N;i=i+1){
			l[i][0]=l[i-1][0],r[i][0]=r[i-1][0];
			x=v[i][k].size();
			while(x--){
				y=v[i][k][x];
				l[i][0]=min(l[i][0],y);
				r[i][0]=max(r[i][0],y);
			}
		}
		l[N-1][1]=N,r[N-1][1]=0;
		for(i=N-2;i>=0;i=i-1){
			l[i][1]=l[i+1][1],r[i][1]=r[i+1][1];
			x=v[i][k].size();
			while(x--){
				y=v[i][k][x];
				l[i][1]=min(l[i][1],y);
				r[i][1]=max(r[i][1],y);
			}
		}
		for(i=0;i<N;i=i+1){
			if((i&1)==k)
				continue;
			x=max(l[i][0],l[i][1]);
			y=min(r[i][0],r[i][1]);
			if(x<y)
				ans+=(LL)(y-x)/2;//,cout<<i<<' '<<v[i][k].size()<<' '<<x<<' '<<y<<endl;
		}
	}
	cout<<ans;
	return 0;
}