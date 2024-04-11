using namespace std;
#include<bits/stdc++.h>
int main() {
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1;i <= n; i ++) {
		for(int j = 1;j <= i - 1;j ++) {
			int p = i * i - j * j;
			int pp =(int)sqrt(p);
			if(pp * pp == p) ans ++;
		}
	}
	cout<<ans/2<<endl;
}