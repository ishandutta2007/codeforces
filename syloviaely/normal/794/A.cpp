#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,L,R;
int main(){
	scanf("%d%d%d",&n,&L,&R);
	scanf("%d",&n); int ans=0;
	for (;n;n--){
		int k1; scanf("%d",&k1);
		if (k1>L&&k1<R) ans++;
	}
	cout<<ans<<endl;
}