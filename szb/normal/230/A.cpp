#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1005;
int x[maxn],y[maxn];
struct node{int x,y,id;}f[maxn];
bool cmp(node a,node b){return a.x<b.x;}
int main(){
    int n,s;scanf("%d%d",&s,&n);
    for(int i=1;i<=n;i++)
	  scanf("%d%d",&f[i].x,&f[i].y),f[i].id=i;
	sort(f+1,f+1+n,cmp);
	for(int i=1;i<=n;i++){
	   if(s<=f[i].x){printf("NO");return 0;}
	   s+=f[i].y;
	}
	printf("YES");
	return 0;
}