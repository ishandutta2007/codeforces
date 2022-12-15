#include <bits/stdc++.h>
using namespace std;

string s; int x, y, a[4]={6,2,4,8}, b[4]={1,3,9,7}, c[4]={6,4,6,4}; 

int main(){
	cin >> s;
	while(s.size()>2) s.erase(s.begin());
	x = atoi(s.c_str());
	if(x==0) printf("4\n");
	else printf("%d\n",(1+a[x%4]+b[x%4]+c[x%4])%5);
	return 0;
}