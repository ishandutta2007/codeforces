#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
struct atom{
	int x,y;
	void scan(){
		scanf("%d%d",&x,&y);
	}
};
int operator < (atom k1,atom k2){
	return k1.x<k2.x||(k1.x==k2.x&&k1.y<k2.y);
}
map<atom,int>M;
map<int,int>A,B;
long long ans=0;
int n;
int get(atom k1){
	int ans=0;
	ans+=A[k1.x]+B[k1.y]-M[k1];
	M[k1]++; A[k1.x]++; B[k1.y]++;
	return ans;
}
int main(){
	scanf("%d",&n); long long ans=0;
	for (;n;n--){
		atom k1; k1.scan(); ans+=get(k1);
	}
	cout<<ans<<endl;
	return 0;
}