//CF 947C
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
typedef double DB;
const int N = 333333;
const int inf = (1<<30)-1;
int tot=1;
struct node{
	int x;
	int ls,rs;
}T[N<<5];
int modify(int v,int k=1,int l=0,int r=inf){
	if(!k)
		k=++tot;
	T[k].x++;
	if(l==r)
		return k;
	int h=l+r>>1;
	if(v<=h)
		T[k].ls=modify(v,T[k].ls,l,h);
	else
		T[k].rs=modify(v,T[k].rs,h+1,r);
	return k;
}
int query(int v,int k=1,int l=0,int r=inf){
	T[k].x--;;
	if(l==r)
		return l;
	int h=l+r>>1;
	if((v^l)<=(v^(h+1))){
		if(T[T[k].ls].x)
			return query(v,T[k].ls,l,h);
		return query(v,T[k].rs,h+1,r);
	}
	if(T[T[k].rs].x)
		return query(v,T[k].rs,h+1,r);
	return query(v,T[k].ls,l,h);
}
int n,a[N],b[N];
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=n;i=i+1)
		scanf("%d",b+i),modify(b[i]);
	for(i=1;i<=n;i=i+1)
		cout<<(a[i]^query(a[i]))<<' ';
	return 0;
}