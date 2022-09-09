#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define mp make_pair
struct Point
{
	int x,y;
	inline bool operator == (const Point &b)
	{
		return (x==b.x) && (y==b.y);
	}
	Point(){}
	Point(int a, int b){ x=a,y=b;}
} p;
vector<Point> P;
int ver,hor;
map<pair<int,int> ,int> mapa;
int main()
{
	int x1,y1,x2,y2,i,j;
	bool ok,te=true;
	for(i=0;i<4;i++)
	{
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		if(x1==x2) ver++;
		if(y1==y2) hor++;
		if((x1!=x2 && y1!=y2) || (x1==x2 && y1==y2)) te=false;
		ok=true;
		p=Point(x1,y1);
		mapa[mp(x1,y1)]++;
		for(j=0;j<P.size();j++) if(P[j]==p) ok=false;
		if(ok) P.push_back(p);
		ok=true;
		p=Point(x2,y2);
		mapa[mp(x2,y2)]++;
		for(j=0;j<P.size();j++) if(P[j]==p) ok=false;
		if(ok) P.push_back(p);
	}
	ok=true;
	for(i=0;i<P.size();i++) if(mapa[mp(P[i].x,P[i].y)]!=2) ok=false;
	if(P.size()==4 && ver==2 && hor==2 && ok && te) printf("YES\n");
	else printf("NO\n");
	return 0;
}