#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x,y,temp;
	cin>>x>>y;
	int i=0;
	int a=y,b=y,c=y;
	while(b!=x || c!=x || a!=x){
		a=min(x,b+c-1);
		temp=a;
		a=b;
		b=c;
		c=temp;
		i++;
	}
	cout<<i;
}