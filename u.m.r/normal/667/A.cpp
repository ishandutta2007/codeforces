#include<bits/stdc++.h>

using namespace std;

int main(){
	double pi = acos(-1);
	double d,h,v,e;
	cin>>d>>h>>v>>e;
	double s = pi * d * d / 4.0;
	double l = v / s;
	if (l <= e + 1e-8)
		puts("NO");
	else{
		puts("YES");
		printf("%.16f\n", h / (l - e));
	}
	return 0;
}