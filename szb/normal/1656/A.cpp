
#include<bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i = (int)(x);i <= (int)(y);++i)
map<long long,long long>mp;
int n,a[10001000],k;
int main(){
	long long T;
	scanf("%lld",&T);
	for(;T--;mp.clear()){
		scanf("%d",&n);	
		int sum=0,id1=1,id2=1;
		For(i,1,n)scanf("%d",&a[i]),id1=a[id1]<a[i]?id1:i,
									id2=a[id2]>a[i]?id2:i;
		cout<<id1<<' '<<id2<<endl;
	}
}