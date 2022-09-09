#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
const int M=4*N;
int n,m;
int FindMain(int x, int y){ return n-x+y;}
int FindSub(int x, int y){ return x+y-1;}
int Get(int t, int x, int y){ return t==0?FindMain(x,y):FindSub(x,y);}
int Dist(int t, int x1, int y1, int x2, int y2)
{
	return max(abs(Get(t^1,x1,y1)-Get(t^1,x2,y2))/2,
				abs(Get(t,x1,y1)-Get(t,x2,y2))/2);
}
int root_main,root_sub,tsz,ls[M],rs[M],sum[M];
void Inc(int &c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return;
    if(!c) c=++tsz;
    if(qs<=ss && qe>=se){ sum[c]++;return;}
	int mid=ss+se>>1;
	Inc(ls[c],ss,mid,qs,qe);
	Inc(rs[c],mid+1,se,qs,qe);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se) return sum[c];
	int mid=ss+se>>1;
	if(qi<=mid) return sum[c]+Get(ls[c],ss,mid,qi);
	else return sum[c]+Get(rs[c],mid+1,se,qi);
}
int state[2][N],l[2][N],r[2][N],sz,was[2][N];
void UpdMain(int id, int s, int e)
{
	was[0][id]++;
	if(s>e) swap(s,e);
	if(!state[0][id]){ Inc(root_main,1,sz,s,e),l[0][id]=s,r[0][id]=e,state[0][id]=1;return;}
    if(l[0][id]<=s && r[0][id]>=e) return;
    if(r[0][id]<e) Inc(root_main,1,sz,r[0][id]+1,e),r[0][id]=e;
	if(l[0][id]>s) Inc(root_main,1,sz,s,l[0][id]-1),l[0][id]=s;
}
void UpdSub(int id, int s, int e)
{
	was[1][id]++;
	if(s>e) swap(s,e);
	if(!state[1][id]){ Inc(root_sub,1,sz,s,e),l[1][id]=s,r[1][id]=e,state[1][id]=1;return;}
    if(l[1][id]<=s && r[1][id]>=e) return;
    if(r[1][id]<e) Inc(root_sub,1,sz,r[1][id]+1,e),r[1][id]=e;
	if(l[1][id]>s) Inc(root_sub,1,sz,s,l[1][id]-1),l[1][id]=s;
}
vector<pair<int,int> > point[2][N];
map<int,map<int,int> > has[2];
int main()
{
	int x,y,i,j;
	string dir;
	scanf("%i %i",&n,&m);
	scanf("%i %i",&x,&y);
	cin >> dir;sz=n+m-1;
	int cnt=0,need=0;
	for(i=1;i<=m;i++)
	{
		if((i+1)%2==(x+y)%2) need++;//,printf("%i %i\n",1,i);
		if((i+n)%2==(x+y)%2) need++;//,printf("%i %i\n",n,i);
		point[0][Get(0,1,i)].pb(mp(1,i));
		point[0][Get(0,n,i)].pb(mp(n,i));
		point[1][Get(1,1,i)].pb(mp(1,i));
		point[1][Get(1,n,i)].pb(mp(n,i));
	}
	for(i=2;i<n;i++)
	{
		if((i+1)%2==(x+y)%2) need++;//,printf("%i %i\n",i,1);
		if((i+m)%2==(x+y)%2) need++;//,printf("%i %i\n",i,m);
		point[0][Get(0,i,1)].pb(mp(i,1));
		point[0][Get(0,i,m)].pb(mp(i,m));
		point[1][Get(1,i,1)].pb(mp(i,1));
		point[1][Get(1,i,m)].pb(mp(i,m));
	}
	for(i=1;i<=sz;i++) sort(point[0][i].begin(),point[0][i].end());
	for(i=1;i<=sz;i++) sort(point[1][i].begin(),point[1][i].end());
	int myx=x,myy=y,ms;ll sol=0;
	if(x==1 && y==1) dir="DR";
	if(x==1 && y==m) dir="DL";
	if(x==n && y==1) dir="UR";
	if(x==n && y==m) dir="UL";
	if(dir=="DR") tie(myx,myy)=point[0][Get(0,x,y)][1],ms=1;
	if(dir=="UL") tie(myx,myy)=point[0][Get(0,x,y)][0],ms=1;
	if(dir=="UR") tie(myx,myy)=point[1][Get(1,x,y)][0],ms=0;
	if(dir=="DL") tie(myx,myy)=point[1][Get(1,x,y)][1],ms=0;
	if(mp(myx,myy)!=mp(x,y) && (x==1 || x==n || y==1 || y==m)) cnt++,has[ms^1][x][y]++;
	if((myx==1 || myx==n) && (myy==1 || myy==m)) ms^=1;
	sol+=Dist(ms^1,x,y,myx,myy)+1;
	//printf("need: %i\n",need);
	//printf("sol:%lld\n",sol);
	while(cnt<need)
	{
		//printf("(%i %i)\n",myx,myy);
		if(!has[ms][myx][myy] && !has[ms^1][myx][myy]) cnt++;
		if(cnt==need) break;
		has[ms][myx][myy]++;
		if(has[ms][myx][myy]>2) return 0*printf("-1\n");
		sol+=Dist(ms,point[ms][Get(ms,myx,myy)][0].first,point[ms][Get(ms,myx,myy)][0].second,point[ms][Get(ms,myx,myy)][1].first,point[ms][Get(ms,myx,myy)][1].second);
        //printf("sol:%lld\n",sol);
        //for(auto out:point[ms][Get(ms,myx,myy)]) printf("[%i %i]\n",out.first,out.second);
        if(mp(myx,myy)==point[ms][Get(ms,myx,myy)][0]) tie(myx,myy)=point[ms][Get(ms,myx,myy)][1];
        else tie(myx,myy)=point[ms][Get(ms,myx,myy)][0];
        if((myx==1 || myx==n) && (myy==1 || myy==m)) ms^=1;
        ms^=1;
	}
	printf("%lld\n",sol);
	return 0;
}