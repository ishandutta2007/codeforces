using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
#define N 100001
#define LL long long
int s;
int n,m,p,x,y;
bool pd(int x) {
	int i=(x/50)%475;
	for(int j=1;j<=25;j++) {
		i=(i*96+42)%475;
		if(i+26==p) return 1;
	}
	return 0;
}
int ans=0;
int main() {
	cin>>p>>x>>y;
	if(x>=y) {
		int k=x;
		while(k>=y) {
			if(pd(k)) {
				cout<<0<<endl;return 0;
			}
			k-=50;
		}
	}
	while(x<y-50) {
		ans++;x+=100;
	} 
	if(x>=y) if(pd(x)) {
		cout<<ans<<endl;return 0;
	}
	while(1) {
		ans++;
		if(pd(x+50)||pd(x+100)) {
			cout<<ans<<endl;return 0;
		}
		x+=100;
	}
}