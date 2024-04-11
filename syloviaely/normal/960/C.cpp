#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=100000;
int x,d;
vector<long long>A;
int main(){
	scanf("%d%d",&x,&d);
	long long cur=1;
	while (x){
		int now=1,num=1;
		while ((now*2+1)<x) now=(now*2+1),num++;
		x-=now;
		for (int i=1;i<=num;i++) A.push_back(cur);
		cur+=d+1;
	}
	printf("%d\n",(int)A.size());
	for (int i=0;i<A.size();i++) printf("%lld ",A[i]);
}