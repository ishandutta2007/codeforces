//CF 274E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int K = 555555;
const int N = 111111;
int n,m,k;
int x[K],y[K];
set<pair<int,int> > S;
set<int> S1[N*2],S2[N*2];
set<int>::iterator it;
vector<pair<int,int> > V1[N*2],V2[N*2],V[N*2];
int T[N*2][2];
void modify(int p,int v){
	if(!p)
		return;
	int o=p&1;
	while(p<N*2){
		T[p][o]+=v;
		p+=p&-p;
	}
}
int query(int p){
	int v=0,o=p&1;
	while(p){
		v+=T[p][o];
		p-=p&-p;
	}
	return v;
}
int main()
{
	int i,px,py,dir,cx,cy,dx,dy,cdx,cdy,hx,hy,t,f,o;
	LL ans;
	char ch[5];
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i=i+1){
		scanf("%d%d",x+i,y+i);
		S1[x[i]+y[i]].insert(x[i]);
		S2[x[i]-y[i]+N].insert(x[i]);
	}
	for(i=0;i<=m+1;i=i+1){
		k++;
		x[k]=0,y[k]=i;
		S1[0+i].insert(x[k]);
		S2[0-i+N].insert(x[k]);
		k++;
		x[k]=n+1,y[k]=i;
		S1[n+1+i].insert(x[k]);
		S2[n+1-i+N].insert(x[k]);
	}
	for(i=1;i<=n;i=i+1){
		k++;
		x[k]=i,y[k]=0;
		S1[i+0].insert(x[k]);
		S2[i-0+N].insert(x[k]);
		k++;
		x[k]=i,y[k]=m+1;
		S1[i+(m+1)].insert(x[k]);
		S2[i-(m+1)+N].insert(x[k]);
	}
	for(i=1;i<=k;i=i+1)
		S.insert(make_pair(x[i],y[i]));
	scanf("%d%d%s",&px,&py,&ch);
	if(ch[0]=='S')
		dx=1;
	else
		dx=-1;
	if(ch[1]=='E')
		dy=1;
	else
		dy=-1;
	if(dx==dy)
		dir=2;
	else
		dir=1;
	while(S.find(make_pair(px+dx,py+dy))==S.end()){
		px+=dx;
		py+=dy;
	}
	cx=px;
	cy=py;
	cdx=dx;
	cdy=dy;
	ans=0;
	f=1;
	while(1){
		hx=dx;
		hy=dy;
		if(S.find(make_pair(px+dx,py))!=S.end())
			hx=-hx;
		if(S.find(make_pair(px,py+dy))!=S.end())
			hy=-hy;
		if(hx==dx&&hy==dy)
			hx=-hx,hy=-hy;
		if(hx==dx)
			px+=dx;
		if(hy==dy)
			py+=dy;
		if(hx==-dx&&hy==-dy)
			f=2;
		else
			dir^=3;
		dx=hx;
		dy=hy;
		if(dir==1){
			t=px+py;
			it=S1[t].lower_bound(px);
			hx=*it;
			it--;
			hy=*it;
			o=px-py+N;
			px=hx+hy-px;
			py=t-px;
			V1[t].push_back(make_pair(o,px-py+N));
			o=max(hx-hy,hy-hx);
			ans+=(LL)o-1;
		}
		else{
			t=px-py;
			it=S2[t+N].lower_bound(px);
			hx=*it;
			it--;
			hy=*it;
			o=px+py;
			px=hx+hy-px;
			py=px-t;
			V2[t+N].push_back(make_pair(o,px+py));
			o=max(hx-hy,hy-hx);
			ans+=(LL)o-1;
		}
		if(px==cx&&py==cy&&dx==cdx&&dy==cdy)
			break;
	}
	for(i=0;i<N*2;i=i+1){
		o=V1[i].size();
		while(o--){
			hx=V1[i][o].first;
			hy=V1[i][o].second;
			V[min(hx,hy)].push_back(make_pair(o,1));
			V[max(hx,hy)].push_back(make_pair(o,-1));
		}
	}
	for(i=0;i<N*2;i=i+1){
		o=V[i].size();
		while(o--){
			hx=V[i][o].first;
			hy=V[i][o].second;
			modify(hx,hy);
		}
		o=V2[i].size();
		while(o--){
			hx=V2[i][o].first;
			hy=V2[i][o].second;
			ans-=query(max(hx,hy))-query(min(hx,hy));
		}
	}
	cout<<ans/f<<endl;
	return 0;
}