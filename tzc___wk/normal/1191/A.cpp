#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n%4==0||n%4==1||n%4==3)	cout<<(5-n%4)%4<<" A\n";
	else						puts("1 B");
	return 0;
}