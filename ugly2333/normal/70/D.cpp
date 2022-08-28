//CF 70D
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
const int N = 111111;
const LL inf = 1e18;
struct pt{
	int x;
	int y;
}p,le,ri;
void PT(int X,int Y){
	p.x=X;
	p.y=Y;
}
bool operator <(pt p1,pt p2){
	return p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y);
}
bool operator ==(pt p1,pt p2){
	return p1.x==p2.x&&p1.y==p2.y;
}
LL dist(pt p1,pt p2){
	return (LL)(p1.x-p2.x)*(p1.x-p2.x)+(LL)(p1.y-p2.y)*(p1.y-p2.y);
}
struct ln{
	int a;
	int b;
	LL c;
}l,o;
void LN(pt p1,pt p2){
	if(p2<p1)
		swap(p1,p2);
	l.a=p1.y-p2.y;
	l.b=p2.x-p1.x;
	l.c=(LL)l.a*p1.x+(LL)l.b*p1.y;
}
LL cal(pt p1,ln l1){
	return (LL)l.a*p1.x+(LL)l.b*p1.y-l.c;
}
set<pt> S,S1,S2;
set<pt>::iterator it,itr;
void prt(pt p1){
	cout<<p1.x<<p1.y<<' ';
}
void prt(ln l1){
	cout<<l1.a<<l1.b<<l1.c<<endl;
}
void prt(set<pt>& ss){
	for(it=ss.begin();it!=ss.end();it++)
		prt(*it);
	cout<<endl;
}/**/
bool isin(){
	if(p<le||ri<p)
		return 0;
	LL h=cal(p,o);
	//cout<<"isin "<<h<<' ';
	if(!h)
		return 1;
	if(h>0){
		it=S1.lower_bound(p);
		itr=it,itr--;
		if((*it).x==p.x)
			return (*it).y>=p.y;
		LN(*it,*itr);
		//prt(*it),prt(*itr),prt(l);
		return (cal(p,l)<=0);
	}
	else{
		it=S2.lower_bound(p);
		itr=it,it--;
		if((*it).x==p.x)
			return (*it).y<=p.y;
		LN(*it,*itr);
		return (cal(p,l)>=0);
	}
}
vector<pt> tmp;
void chk1(){
	LL h;
	S1.insert(p);
	it=S1.lower_bound(p);
	it++;
	if(it!=S1.end()){
		itr=it,itr++;
		while(itr!=S1.end()){
			LN(p,*itr);
			h=cal(*it,l);
			if(h<=0)
				tmp.push_back(*it);
			else
				break;
			it++,itr++;
		}
	}
	it=S1.lower_bound(p);
	if(it!=S1.begin()){
		it--;
		itr=it,itr--;
		while(it!=S1.begin()){
			LN(p,*itr);
			h=cal(*it,l);
			if(h<=0)
				tmp.push_back(*it);
			else
				break;
			it--,itr--;
		}
	}
	int i;
	for(i=tmp.size()-1;i>=0;i=i-1)
		S1.erase(tmp[i]);
	tmp.clear();
}
void chk2(){
	LL h;
	S2.insert(p);
	it=S2.lower_bound(p);
	it++;
	if(it!=S2.end()){
		itr=it,itr++;
		while(itr!=S2.end()){
			LN(p,*itr);
			h=cal(*it,l);
			if(h>=0)
				tmp.push_back(*it);
			else
				break;
			it++,itr++;
		}
	}
	it=S2.lower_bound(p);
	if(it!=S2.begin()){
		it--;
		itr=it,itr--;
		while(it!=S2.begin()){
			LN(p,*itr);
			h=cal(*it,l);
			if(h>=0)
				tmp.push_back(*it);
			else
				break;
			it--,itr--;
		}
	}
	int i;
	for(i=tmp.size()-1;i>=0;i=i-1)
		S2.erase(tmp[i]);
	tmp.clear();
}
int main()
{
	int n,i,j,t,x,y;
	LL h;
	scanf("%d",&n);
	for(i=1;i<=2;i=i+1){
		scanf("%d%d%d",&t,&x,&y);
		PT(x,y);
		S.insert(p);
		S1.insert(p);
		S2.insert(p);
	}
	for(i=3;i<=n;i=i+1){
		le=*S.begin(),ri=*S.rbegin();
		LN(le,ri),o=l;
		//prt(S),prt(S1),prt(S2),prt(o);
		scanf("%d%d%d",&t,&x,&y);
		PT(x,y);
		if(t==1){
			if(isin())
				continue;
			S.insert(p);
			if(p<le||ri<p){
				chk1();
				chk2();
				continue;
			}
			h=cal(p,o);
			if(h>0)
				chk1();
			else
				chk2();
		}
		else{
			if(isin())
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}