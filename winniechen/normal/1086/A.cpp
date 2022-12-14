#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
struct node{int x,y;}s[10];
bool cmp(const node &a,const node &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int main()
{
	for(int i=1;i<=3;i++)scanf("%d%d",&s[i].x,&s[i].y);
	sort(s+1,s+4,cmp);
	int l=min(s[1].y,min(s[2].y,s[3].y)),r=max(s[1].y,max(s[2].y,s[3].y));
	printf("%d\n",(s[3].x-s[1].x)+r-l+1);
	for(int i=l;i<=r;i++)printf("%d %d\n",s[2].x,i);
	for(int i=s[1].x;i<s[2].x;i++)printf("%d %d\n",i,s[1].y);
	for(int i=s[2].x+1;i<=s[3].x;i++)printf("%d %d\n",i,s[3].y);
}