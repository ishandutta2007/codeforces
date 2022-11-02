#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000
#define N 500500

using namespace std;

struct Tree{
	int l,r,min,add;
};

Tree tr[N];
int a[N],b[N],tb[N],ans,n,len,h;

void build(int x,int l,int r){
	tr[x].l=l;
	tr[x].r=r;
	tr[x].add=0;
	if (l==r)
		tr[x].min=-l-1;
	else {
		build(x+x,l,(l+r)/2);
		build(x+x+1,(l+r)/2+1,r);
		tr[x].min=min(tr[x+x].min,tr[x+x+1].min);
	}
}

void add(int x,int l,int val){
	if (tr[x].r<l)return;
	if (tr[x].l>=l){tr[x].add+=val;return;}
	add(x+x,l,val);
	add(x+x+1,l,val);
	tr[x].min=min(tr[x+x].min+tr[x+x].add,tr[x+x+1].min+tr[x+x+1].add);
}

int main(){
	scanf("%d%d%d",&n,&len,&h);
	for (int i=0;i<len;i++)scanf("%d",&b[i]);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(b,b+len);
	build(1,0,len-1);
	for (int i=0;i<n;i++){
		int l=-1,r=len;
		while (l<r-1)
			if (b[(l+r)/2]+a[i]>=h)
				r=(l+r)/2;
			else l=(l+r)/2;
		tb[i]=r;
		add(1,r,1);
		if (i>=len)add(1,tb[i-len],-1);
		if (tr[1].min+tr[1].add>=0)++ans;
	}
	printf("%d\n",ans);
}