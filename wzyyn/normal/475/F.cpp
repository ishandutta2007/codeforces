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
set<pii> X,Y;
int n,ans;
pii q[100005];
void solve(set<pii> &X,set<pii> &Y){
	set<pii> xx,yy;
	auto x1=X.begin(),y1=Y.begin();
	auto x2=X.rbegin(),y2=Y.rbegin();
	int top=0;
	for (;*x1<*x2;){
		int tmp;
		tmp=x1->fi;
		if ((++x1)->fi-tmp>1){
			for (auto it=X.begin();*it<*x1;++it)
				q[++top]=pii(it->fi,it->se);
			break;
		}
		tmp=x2->fi;
		if (tmp-(++x2)->fi>1){
			for (auto it=X.rbegin();*it>*x2;++it)
				q[++top]=pii(it->fi,it->se);
			break;
		}
		tmp=y1->fi;
		if ((++y1)->fi-tmp>1){
			for (auto it=Y.begin();*it<*y1;++it)
				q[++top]=pii(it->se,it->fi);
			break;
		}
		tmp=y2->fi;
		if (tmp-(++y2)->fi>1){
			for (auto it=Y.rbegin();*it>*y2;++it)
				q[++top]=pii(it->se,it->fi);
			break;
		}
	}
	if (!top){
		++ans;
		return;
	}
	//assert(top);
	For(i,1,top){
		pii it=q[i],jt(it.se,it.fi);
		xx.insert(it); yy.insert(jt);
		X.erase(it);   Y.erase(jt);
	}
	solve(X,Y);
	solve(xx,yy);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		X.insert(pii(x,y));
		Y.insert(pii(y,x));
	}
	solve(X,Y);
	printf("%d\n",ans);
}