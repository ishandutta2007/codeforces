//*

#include<stdio.h>
#include<vector>
#define MN 1000000

using namespace std;

int N;

struct POINT {
	int x,y;
	int ind;
}P[MN];

vector<POINT> p1,p2,p3,p4;
vector<int> ans;

void dfs(int s,int e,int x1,int y1,int x2,int y2) {
	if(e<s)return;
	if(s==e) {
		ans.push_back(P[s].ind);
		return;
	}
	int xm=(x1+x2)>>1;
	int ym=(y1+y2)>>1;
	p1.clear(),p2.clear(),p3.clear(),p4.clear();
	for(int i=s;i<=e;i++) {
		int x=P[i].x;
		int y=P[i].y;
		if(xm<x && ym<y) {
			p1.push_back(P[i]);
		}
		else if(x<=xm && ym<y) {
			p2.push_back(P[i]);
		}
		else if(x<=xm && y<=ym) {
			p3.push_back(P[i]);
		}
		else {
			p4.push_back(P[i]);
		}
	}
	int c=s;
	for(auto p:p1)P[c++]=p;
	for(auto p:p2)P[c++]=p;
	for(auto p:p3)P[c++]=p;
	for(auto p:p4)P[c++]=p;
	int s1=p1.size(),s2=p2.size(),s3=p3.size(),s4=p4.size();
	dfs(s,s+s1-1,xm+1,ym+1,x2,y2);
	s+=s1;
	dfs(s,s+s2-1,x1,ym+1,xm,y2);
	s+=s2;
	dfs(s,s+s3-1,x1,y1,xm,ym);
	s+=s3;
	dfs(s,s+s4-1,xm+1,y1,x2,ym);
	s+=s4;
}

int main() {
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d%d",&P[i].x,&P[i].y);
		P[i].ind=i;
	}
	dfs(0,N-1,0,0,MN,MN);
	for(auto n:ans)printf("%d ",n+1);
	return 0;
}

//*/