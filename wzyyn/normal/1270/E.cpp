#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n,x[5005],y[5005];
vector<int> vec[2][2];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) x[i]+=1<<20,y[i]+=1<<20;
	for (int v=0;v<=25;++v){
		bool fl0=0,fl1=0;
		For(i,1,n){
			int v0=(x[i]>>v)&1;
			int v1=(y[i]>>v)&1;
			vec[v0][v1].PB(i);
		}
		//printf("%d %d %d %d\n",vec[0][0].size(),vec[0][1].size(),vec[1][0].size(),vec[1][1].size());
		if (vec[0][0].size()+vec[1][1].size())
			if (vec[0][1].size()+vec[1][0].size()){
				printf("%d\n",vec[0][0].size()+vec[1][1].size());
				for (auto i:vec[0][0]) printf("%d ",i);
				for (auto i:vec[1][1]) printf("%d ",i);
				return 0;
			}
		if (vec[0][0].size()&&vec[1][1].size()){
			printf("%d\n",vec[0][0].size());
			for (auto i:vec[0][0]) printf("%d ",i);
			return 0;
		}
		if (vec[0][1].size()&&vec[1][0].size()){
			printf("%d\n",vec[0][1].size());
			for (auto i:vec[0][1]) printf("%d ",i);
			return 0;
		}
		For(i,0,1) For(j,0,1)
			vec[i][j].resize(0);
	}
}
/*
00 01:%4=1
00 11:%4=2
00 10:%4=1
01 10:%4=2
01 11:%4=1
11 11:%4= 
*/