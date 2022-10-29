#include<iostream>
#include<cstdio> 
#include<cstring> 
#include<algorithm>
#include<string>
using namespace std;
#define N 200010
#define LL long long

class point{
public:
	int x=0,y=0;
	bool operator<(point a){return max(this->x,this->y)<max(a.x,a.y);}
	bool operator>(point a){return max(this->x,this->y)<max(a.x,a.y);}
	bool isleft(point a){
		return (this->x<a.x)||(this->y>a.y);
	}
	int level(){return max(this->x,this->y);}
	int distance(point a){return abs(this->x-a.x)+abs(this->y-a.y);}
};
point a[N];
LL upleft[N],downright[N];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x;a[i].y=y;
	}
	sort(a+1, a+n+1);
	int level, m=0;
	point l1,r1;
	for(int i=1;i<=n;){
		level = a[i].level();
		point l,r;
		while(a[i].level()==level){
			if((l.level()<level)||(a[i].isleft(l))) l=a[i];
			if((r.level()<level)||(r.isleft(a[i]))) r=a[i];
			++i;
		}
		++m;
		upleft[m]=min(upleft[m-1]+r.distance(l1),downright[m-1]+r.distance(r1))+l.distance(r);
		downright[m]=min(upleft[m-1]+l.distance(l1),downright[m-1]+l.distance(r1))+r.distance(l);
		l1=l;r1=r;
	}
	//cout<<endl;
	//for(int i=1;i<=m;i++)printf("%lld %lld\n",upleft[i],downright[i]);
	printf("%lld\n",min(upleft[m],downright[m]));
	return 0;
}