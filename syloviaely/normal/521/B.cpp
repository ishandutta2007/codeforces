#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
priority_queue<int,vector<int>,greater<int> >Q2;
priority_queue<int>Q1;
struct point{
	int x,y,where;
}x[110000];
int operator < (point k1,point k2){
	return k1.x<k2.x||(k1.y<k2.y&&k1.x==k2.x);
}
set<point>S;
int n,ans[110000],len,pd[110000],w1[110000],w2[110000],mo=1e9+9;
void add(int i){
	for (int j=x[i].x-1;j<=x[i].x+1;j++){
		point k1=(point){j,x[i].y-1,0};
		set<point>::iterator k2=S.find(k1);
		if (k2!=S.end()&&pd[(*k2).where]==0) w2[(*k2).where]++;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {scanf("%d%d",&x[i].x,&x[i].y); x[i].where=i;}
	for (int i=1;i<=n;i++) S.insert(x[i]);
	for (int i=1;i<=n;i++)
		if (x[i].y!=0){
			int num=0;
			for (int j=x[i].x-1;j<=x[i].x+1;j++){
				point k1=(point){j,x[i].y-1,0};
				set<point>::iterator k2=S.find(k1);
				if (k2!=S.end()) {w1[i]++; num=(*k2).where;}
			}
			if (w1[i]==1) w2[num]++;
		}
	for (int i=1;i<=n;i++)
		if (w2[i]==0) {Q1.push(i); Q2.push(i);}
	memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++){
		int where=0;
		if (i%2==1){
			while (pd[Q1.top()]||w2[Q1.top()]) Q1.pop();
			where=Q1.top();
		} else {
			while (pd[Q2.top()]||w2[Q2.top()]) Q2.pop();
			where=Q2.top();
		}
		pd[where]=1; ans[i]=where-1;
		if (w1[where]==1)
			for (int j=x[where].x-1;j<=x[where].x+1;j++){
				point k1=(point){j,x[where].y-1,0};
				set<point>::iterator k2=S.find(k1);
				if (k2!=S.end()) {
					int k3=(*k2).where; 
					if (pd[k3]==0){
						w2[k3]--; if (w2[k3]==0){Q1.push(k3); Q2.push(k3);}
					}
				}
			}
		for (int j=x[where].x-1;j<=x[where].x+1;j++){
			point k1=(point){j,x[where].y+1,0};
			set<point>::iterator k2=S.find(k1);
			if (k2!=S.end()) {
				int k3=(*k2).where; if (pd[k3]) continue;
				w1[k3]--;
				if (w1[k3]==1) add(k3);
			}
		}
	}
	int num=0;
	for (int i=1;i<=n;i++) num=(1ll*num*n+ans[i])%mo;
	cout<<num<<endl;
}