#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
int a[5];
int main(){
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);cout<<a[2]-a[0]<<endl;
	return 0;
}