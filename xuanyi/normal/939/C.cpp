#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=200005;
int n,max_x,id,A[MAXN],s,f,S[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),A[i+n]=A[i];
	for (int i=1;i<=(n<<1);i++) S[i]=S[i-1]+A[i];
	scanf("%d%d",&s,&f); --s+=n,--f+=n;
	id=1,max_x=S[f--]-S[s--];
	for (int i=2;i<=n;i++){
		int x=S[f--]-S[s--];
		if (max_x<x) max_x=x,id=i;
	}
	printf("%d\n",id);
	return 0;
}