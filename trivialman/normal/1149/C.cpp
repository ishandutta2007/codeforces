#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 2e5+5;

struct dat{
	int d, m1, m2, m12, m21, ans;
	dat(char ch=0){
		if(ch!='(' && ch!=')') return;
		d = ch=='(' ? 1 : -1;
		m1 = d, m2 = -d*2, m12 = m21 = -d, ans = 0;
	}
	dat operator+(dat y){
		dat res;
		res.d = d + y.d;
		res.m1 = max(m1, d + y.m1);
		res.m2 = max(m2, -(d<<1) + y.m2);
		res.m12 = max(max(m12, -d + y.m12), m1 - (d<<1) + y.m2);
		res.m21 = max(max(m21, -d + y.m21), m2 + d + y.m1);
		res.ans = max(max(ans, y.ans), max(m1-d+y.m21, m12+d+y.m1) );
		return res;
	}
}tr[(1<<19)+5];

int n,q,x,y;
char s[N];

void upd(int i,dat x,int id=1,int l=1,int r=n){
	if(l==r) {tr[id] = x; return;}
	int mid = l+r>>1;
	if(i<mid) upd(i,x,id<<1,l,mid);
	else upd(i,x,id<<1|1,mid+1,r);
	tr[id] = tr[id<<1] + tr[id<<1|1];
}

int main() {
	scanf("%d%d",&n,&q);
	n = n-1<<1;
	scanf("%s",s+1);
	rep(i,1,n) upd(i,dat(s[i]));
	printf("%d\n",tr[1].ans);
	rep(i,1,q){
		scanf("%d%d",&x,&y);
		if(s[x]!=s[y]){
			upd(x, dat(s[y]));
			upd(y, dat(s[x]));
			swap(s[x], s[y]);
		}
		printf("%d\n",tr[1].ans);
	}
}