#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
#define pdd pair<double,double>
int Q,la;
ll MP;
multiset<pdd> S;
pdd operator -(pdd a,pdd b){
	return pdd(a.fi-b.fi,a.se-b.se);
}
double operator *(pdd a,pdd b){
	return a.fi*b.se-a.se*b.fi;
}
bool OK(pdd a,pdd b,pdd c){
	return (b-a)*(c-a)<=1e-10;
}
void insert(pdd x){
	multiset<pdd>::iterator it,ppre,pre,nxt;
	it=S.lower_bound(pdd(x.fi,0));
	if (it!=S.end()&&it->se<=x.se) return;
	pre=it; pre--;
	if (it!=S.end()&&OK(*pre,x,*it)) return;
	nxt=pre=S.insert(x);
	ppre=--pre; --ppre; ++nxt;
	for (;nxt!=S.end()&&nxt->fi==x.fi;S.erase(nxt++));
	for (;pre!=S.begin()&&OK(*ppre,*pre,x);)
		S.erase(pre--),ppre--; 
}
bool query(int a,int b){
	multiset<pdd>::iterator it,pre,nxt;
	it=S.lower_bound(pdd(1.0*b/a,0));
	if (it==S.end()) return 0;
	if (1ll*it->se*a<=MP) return 1;
	//cout<<233<<endl;
	pre=nxt=it; pre--;
	//cout<<pre->fi<<' '<<pre->se<<' '<<nxt->fi<<' '<<nxt->se<<endl;
	//cout<<1.0*b/a<<' '<<1.0*MP/a<<endl;
	return OK(*pre,pdd(1.0*b/a,1.0*MP/a),*nxt);
}
/*
x1,y1
b/a,m
x2,y2
*/
int main(){
	scanf("%d%lld",&Q,&MP);
	S.insert(pii(0,0));
	For(i,1,Q){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		x=(x+la)%1000000+1;
		y=(y+la)%1000000+1;
		//cout<<x<<' '<<y<<endl;
		if (tp==1) insert(pii(x,y));
		else if (query(x,y))
			puts("YES"),la=i;
		else puts("NO");
	}
}