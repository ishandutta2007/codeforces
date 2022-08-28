//CF1572B
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
int n,a[N];
vector<int> v,s;
void solver(int x,int y){
	while(y-x>=3){
		s.push_back(y-2);
		s.push_back(y-1);
		y-=2;
	}
	s.push_back(x);
}
void solvel(int x,int y){
	while(y-x>=3){
		s.push_back(x);
		s.push_back(x-1);
		x+=2;
	}
	s.push_back(y-2);
}
void solvem(int x,int y){
	int i;
	for(i=x;i<y;i+=2)
		s.push_back(i);
	for(i=y-4;i>=x;i-=2)
		s.push_back(i);
}
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=0;
		s.clear();
		v.clear();
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			x^=a[i];
			if(a[i])
				v.push_back(i);
		}
		if(x){
			printf("NO\n");
			continue;
		}
		if(!a[n]){
			for(i=v.size()-1;i>=0;i-=2)
				solver(v[i-1],v[i]);
			printf("YES\n");
			printf("%d\n",s.size());
			for(i=0;i<s.size();i++)
				printf("%d ",s[i]);
			printf("\n");
			continue;
		}
		if(!a[1]){
			for(i=0;i<v.size();i+=2)
				solvel(v[i],v[i+1]);
			printf("YES\n");
			printf("%d\n",s.size());
			for(i=0;i<s.size();i++)
				printf("%d ",s[i]);
			printf("\n");
			continue;
		}
		x=-1;
		for(i=1;i<v.size()-1;i+=2)
			if(v[i]<v[i+1]-1)
				x=i;
		if(x>=0){
			for(i=x;i>=0;i-=2)
				solver(v[i-1],v[i]);
			for(i=x+1;i<v.size();i+=2)
				solvel(v[i],v[i+1]);
			printf("YES\n");
			printf("%d\n",s.size());
			for(i=0;i<s.size();i++)
				printf("%d ",s[i]);
			printf("\n");
			continue;
		}
		x=-1;
		for(i=0;i<v.size()-1;i++)
			if(v[i]%2==v[i+1]%2)
				x=i;
		if(x>=0){
			solvem(v[x],v[x+1]);
			for(i=x-1;i>=0;i-=2)
				solver(v[i-1],v[i]);
			for(i=x+2;i<v.size();i+=2)
				solvel(v[i],v[i+1]);
			printf("YES\n");
			printf("%d\n",s.size());
			for(i=0;i<s.size();i++)
				printf("%d ",s[i]);
			printf("\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}