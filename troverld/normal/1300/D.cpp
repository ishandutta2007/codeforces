#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n;
pair<int,int>p[100100],pp;
set<pair<int,int> >s;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&p[i].x,&p[i].y);
	if(n&1){puts("NO");return 0;}
	for(int i=0;i<n;i++){
		pp=make_pair(p[(i+1)%n].x-p[i].x,p[(i+1)%n].y-p[i].y);
		if(pp.x<0)pp.x*=-1,pp.y*=-1;
		if(pp.x==0)pp.y=abs(pp.y);
//		printf("%d %d\n",pp.x,pp.y);
		s.insert(pp);
	}
	puts(s.size()==n/2?"YES":"NO");
	return 0;
}
/*
6
0 1
2 0
2 -2
1 -3
-1 -2
-1 0
*/