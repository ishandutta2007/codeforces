#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=300050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
int lzy[M],mn[M];
void Build(int &c,int ss,int se){
	c=++tsz;lzy[c]=0;
	if(ss==se)return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(ss>qe || qs>se || qs>qe)return;
	if(qs<=ss && qe>=se){lzy[c]+=f;mn[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
}
int p[N],q[N],pos[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%i",&q[i]);
	int ptr=n+1;
	Build(root,1,n);
	for(int i=0;i<n;i++){
		if(i){
			Add(root,1,n,1,q[i],1);
			//printf("(add 1 %i) ",q[i]);
		}
		//printf("mn:%i ",mn[root]);
		while(ptr>1 && mn[root]>=0){
			ptr--;
			Add(root,1,n,1,pos[ptr],-1);
			//printf("(add -1 %i) ",pos[ptr]);
		}
		printf("%i ",ptr);
	}
	return 0;
}