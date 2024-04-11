//CF 915E
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
const int N = 333333;
int n,q,m,L,R,C;
struct node{
	int x;
	int f;
	int ls;
	int rs;
}T[N*48];
void modify(int k=0,int l=1,int r=n){
	if(L<=l&&r<=R){
		T[k].f=C;
		T[k].x=C*(r-l+1);
		return;
	}
	if(!T[k].ls){
		T[k].ls=++m;
		//T.push_back(w);
	}
	if(!T[k].rs){
		T[k].rs=++m;
		//T.push_back(w);
	}
	int h=(l+r)>>1,c=T[k].f;
	if(c>=0){
		T[T[k].ls].f=c;
		T[T[k].ls].x=c*(h-l+1);
		T[T[k].rs].f=c;
		T[T[k].rs].x=c*(r-h);
		T[k].f=-1;
	}
	if(L<=h)
		modify(T[k].ls,l,h);
	if(h<R)
		modify(T[k].rs,h+1,r);
	T[k].x=T[T[k].ls].x+T[T[k].rs].x;
}
int main()
{
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d%d",&L,&R,&C);
		C=2-C;
		modify();
		printf("%d\n",n-T[0].x);
	}
	return 0;
}