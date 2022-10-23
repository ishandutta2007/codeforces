//CF1746E1
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,m,a[N];
vector<int> v;
char ch[5];
int q(int x,int y=-1){
	int i;
	v.clear();
	for(i=1;i<=m;i++)
		if(i%4==x||i%4==y)
			v.push_back(a[i]);
	printf("? %d ",v.size());
	for(i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",ch);
	return ch[0]=='Y';
}
void era(int x){
	int i,j=0;
	for(i=1;i<=m;i++)
		if(i%4==x)
			a[i]=0;
	for(i=1;i<=m;i++)
		if(a[i])
			a[++j]=a[i];
	m=j;
}
void go1(){
	int r=q(0,1);
	if(r){
		r=q(2);
		if(r)
			era(3);
		else
			era(2);
	}
	else{
		r=q(0);
		if(r)
			era(1);
		else
			era(0);
	}
}
void chk(int x){
	printf("! %d\n",x);
	fflush(stdout);
	scanf("%s",ch);
	if(ch[1]==')')
		exit(0);
}
int main()
{
	int i,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a[i]=i;
	m=n;
	while(m>=4){
		go1();
	}
	if(m==3){
		r=q(3);
		if(!r){
			r=q(3);
			if(!r)
				era(3);
		}
	}
	if(m==3){
		r=q(1);
		if(r)
			era(2);
		else
			era(1);
	}
	chk(a[1]);
	chk(a[2]);
	return 0;
}