//CF 899E
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
const int N = 222222;
struct node{
	int id;
	int len,l;
	int x;
	int pr,nx;
	bool b;
}a[N<<2];
bool operator <(node u,node q){
	return u.len<q.len||(u.len==q.len&&u.l>q.l);
}
priority_queue<node> Q;
int tot;
void addnode(int LEN,int L,int X,int PR,int NX){
	tot++;
	a[tot].id=tot;
	a[tot].len=LEN,a[tot].l=L;
	a[tot].x=X;
	a[tot].pr=PR,a[tot].nx=NX;
	if(PR)
		a[PR].nx=tot;
	if(NX)
		a[NX].pr=tot;
	a[tot].b=1;
	Q.push(a[tot]);
}
void delnode(int k){
	int PR,NX;
	PR=a[k].pr,NX=a[k].nx;
	a[k].b=0;
	if(PR&&NX&&a[PR].x==a[NX].x){
		a[PR].b=0,a[NX].b=0;
		addnode(a[PR].len+a[NX].len,a[PR].l,a[PR].x,a[PR].pr,a[NX].nx);
		return;
	}
	if(PR)
		a[PR].nx=NX;
	if(NX)
		a[NX].pr=PR;
}
int n,ans;
int main()
{
	int i,x,y,h;
	scanf("%d%d",&n,&y);
	h=1;
	for(i=1;i<=n;i=i+1){
		x=y;
		if(i<n)
			scanf("%d",&y);
		if(i==n||x!=y)
			addnode(h,i-h,x,tot,0),h=1;
		else
			h++;
	}
	while(!Q.empty()){
		i=Q.top().id;
		Q.pop();
		if(a[i].b){
			ans++;
			delnode(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}