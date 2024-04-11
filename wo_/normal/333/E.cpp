#include<cstdio>
#include<cmath>
#include<utility>
#include<deque>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

const double PI=3.14159265358979323846264;
const double eps=1e-9;

bool neq(double d1,double d2)
{
	return d1+eps<d2||d2+eps<d1;
}

struct vec{
	double theta;
	int x,y;
	vec(){}
	vec(double t,int x,int y):theta(t),x(x),y(y){}
};

bool cmp(const vec &v1,const vec &v2)
{
	if(neq(v1.theta,v2.theta)) return v1.theta<v2.theta;
	return v1.x<v2.x;
}
/*
struct cmp_{
	bool operator()(const vec &v1,const vec &v2)
	{
		return cmp(v1,v2);
	}
};*/

vec vecs[6060];
/*
struct RMQ{
	int N;
	int dat[16384];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++) dat[i]=0;
	}
	void getArray(int *a,int N_)
	{
		for(int i=0;i<N_;i++) dat[i+N]=a[i];
		for(int i=N_;i<N;i++) dat[i+N]=0;
		for(int i=N-1;i>=1;i--) dat[i]=max(dat[i*2],dat[i*2+1]);
	}
	void update(int i,int x)
	{
		i+=N;
		while(i>0)
		{
			dat[i]=max(dat[i],x);
			i/=2;
		}
	}
	int get(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r) return dat[k];
		if(r<=a||b<=l) return 0;
		return max(get(l,r,k*2,a,(a+b)/2),get(l,r,k*2+1,(a+b)/2,b));
	}
	int get(int l,int r)
	{
		return get(l,r,1,0,N);
	}
};

RMQ rmq;
*/
int N;
int xs[3030],ys[3030];

//int a[8192];

deque<P> deq;

int solve(int id)
{
//	printf("%d %d::\n",xs[id],ys[id]);
	int c=0;
	for(int i=0;i<N;i++)
	{
		if(id==i) continue;
		int dx=xs[i]-xs[id],dy=ys[i]-ys[id];
		double theta=atan2(dy,dx);
		vecs[c++]=vec(theta,dx,dy);
		if(theta<=PI+eps) vecs[c++]=vec(theta+PI*2,dx,dy);
	}
	sort(vecs,vecs+c,cmp);
//	rmq.init(c);
//	for(int i=0;i<c;i++)
//	{
//		int dx=vecs[i].x,dy=vecs[i].y;
		//rmq.update(i,dx*dx+dy*dy);
//		a[i]=dx*dx+dy*dy;
//	}
//	rmq.getArray(a,c);
	int Ma=0;
	int l=0,r=0;
	for(int i=0;i<c;i++)
	{
		double theta=vecs[i].theta;
		int x=vecs[i].x,y=vecs[i].y;
		vec tmp=vec(theta+PI/3,-1<<29,-1<<29);
		int oldl=l,oldr=r;
	//	int l=lower_bound(vecs,vecs+c,tmp,cmp)-vecs;
		while(l<c&&cmp(vecs[l],tmp)) l++;
		tmp.theta=theta+PI;
		tmp.x=1<<29,tmp.y=1<<29;
//		int r=lower_bound(vecs,vecs+c,tmp,cmp)-vecs;
		while(r<c&&cmp(vecs[r],tmp)) r++;
		for(int i=oldr;i<r;i++)
		{
			int curv=vecs[i].x*vecs[i].x+vecs[i].y*vecs[i].y;
			while(!deq.empty()&&deq.back().first<=curv) deq.pop_back();
			deq.push_back(P(curv,i));
		}
		while(!deq.empty()&&deq.front().second<l) deq.pop_front();
		//int dis1=rmq.get(l,r);
		if(l==r) continue;
		int dis1=deq.front().first;
		int dis2=x*x+y*y;
//		printf("%d %d\n",dis1,dis2);
		Ma=max(Ma,min(dis1,dis2));
	}
	return Ma;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d",xs+i,ys+i);
	int Ma=0;
	for(int i=0;i<N;i++) Ma=max(Ma,solve(i));
	printf("%.9f\n",sqrt(Ma)/2);
	return 0;
}