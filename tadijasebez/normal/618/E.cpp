#include <bits/stdc++.h>
using namespace std;
#define ldb long double
const ldb PI=acos(-1);
struct pt{ ldb x,y;pt(){}pt(ldb a, ldb b):x(a),y(b){}pt(int a, int b):x(a),y(b){}};
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
pt operator * (pt a, ldb b){ return pt(a.x*b,a.y*b);}
pt operator / (pt a, ldb b){ return pt(a.x/b,a.y/b);}
ldb operator | (pt a, pt b){ return a.x*b.x+a.y*b.y;}
ldb operator * (pt a, pt b){ return a.x*b.y-a.y*b.x;}
ldb sq(pt a){ return a|a;}
ldb abs(pt a){ return sqrt(sq(a));}
struct matrix{ ldb a[2][2];matrix(){}matrix(ldb ang){ a[0][0]=cos(ang);a[1][0]=sin(ang);a[0][1]=-sin(ang);a[1][1]=cos(ang);}};
pt operator * (matrix m, pt a){ return pt(m.a[0][0]*a.x+m.a[0][1]*a.y,m.a[1][0]*a.x+m.a[1][1]*a.y);}
pt rot(pt cen, pt a, ldb ang)
{
	a=a-cen;
	matrix m=matrix(ang);
	a=m*a;
	a=a+cen;
	return a;
}
pt rot(pt cen, pt a, matrix m)
{
	a=a-cen;
	a=m*a;
	a=a+cen;
	return a;
}
const int N=300050;
ldb ang[N],len[N];
int deg[N];
struct Node
{
	pt fir,sec;
};
Node Merge(Node l, Node r, ldb ang, ldb len)
{
	pt add=l.fir-l.sec;
	add=add/abs(add);
	matrix m;
	m.a[0][0]=add.x;
	m.a[1][0]=add.y;
	m.a[0][1]=-add.y;
	m.a[1][1]=add.x;
	add=add*len;
	Node ans;
	ans.sec=rot(l.fir,r.sec+l.fir,m);
	ans.fir=rot(l.fir,r.fir+l.fir,m);
	ans.sec=rot(l.fir,ans.sec+add,ang);
	ans.fir=rot(l.fir,ans.fir+add,ang);
	return ans;
}
const int M=2*N;
int ls[M],rs[M],tsz,root;
Node node[M];
void Brute(int c, int ss, int se)
{
	pt cur=pt(0,0),las=pt(-1,0);
	for(int i=ss;i<se;i++)
	{
		pt tmp=cur;
		pt add=cur-las;
		add=add/abs(add);
		matrix m;
		m.a[0][0]=add.x;
		m.a[1][0]=add.y;
		m.a[0][1]=-add.y;
		m.a[1][1]=add.x;
		cur=rot(tmp,cur,m);
		add=add*len[i];
		cur=rot(tmp,cur+add,ang[i]);
		las=tmp;
	}
	node[c].fir=cur;
	node[c].sec=las;
}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(se-ss+1<=4){ Brute(c,ss,se);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=Merge(node[ls[c]],node[rs[c]],ang[mid],len[mid]);
}
void Rebuild(int c, int ss, int se, int qi)
{
	if(se-ss+1<=4){ Brute(c,ss,se);return;}
	int mid=ss+se>>1;
	if(qi<=mid) Rebuild(ls[c],ss,mid,qi);
	else Rebuild(rs[c],mid+1,se,qi);
	node[c]=Merge(node[ls[c]],node[rs[c]],ang[mid],len[mid]);
}
int main()
{
	int n,m,i,x,y,z;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) len[i]=1;
	Build(root,1,n+1);
	while(m--)
	{
		scanf("%i %i %i",&x,&y,&z);
		if(x==1) len[y]+=z;
		if(x==2) deg[y]+=z,deg[y]%=360,ang[y]=PI*2-PI*2*deg[y]/360;
		Rebuild(root,1,n+1,y);
		cout<<fixed<<setprecision(12)<<node[root].fir.x<<" "<<node[root].fir.y<<"\n";
	}
	return 0;
}