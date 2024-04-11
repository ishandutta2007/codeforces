#include<bits/stdc++.h>
using namespace std;
struct Point
{
	int x,y;
}p[3];
inline bool operator < (const Point &a,const Point &b)
{
	return a.x<b.x;
}
int main()
{
	for(int i=0;i<=2;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p,p+3);
	int mid=p[1].x;
	int L=min(p[0].y,min(p[1].y,p[2].y));
	int R=max(p[0].y,max(p[1].y,p[2].y));
	typedef tuple<int,int,int,int> T; 
	vector<T> ans;
	if(L!=R)
		ans.push_back(T(mid,L,mid,R));
	if(p[0].x!=mid)
		ans.push_back(T(p[0].x,p[0].y,mid,p[0].y));
	if(p[2].x!=mid)
		ans.push_back(T(mid,p[2].y,p[2].x,p[2].y));
	printf("%d\n",int(ans.size())); 
	for(vector<T>::iterator it=ans.begin();it!=ans.end();++it)
		printf("%d %d %d %d\n",get<0>(*it),get<1>(*it),get<2>(*it),get<3>(*it));
	return 0;
}