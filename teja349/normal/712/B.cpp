#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	char ch=getchar();
	int r=0,u=0;
	while(ch!='\n'){
		if(ch=='U')
			u++;
		else if(ch=='R')
			r++;
		else if(ch=='L')
			r--;
		else if(ch=='D')
			u--;
		ch=getchar();
	}
	if(u<0)
		u*=-1;
	if(r<0)
		r*=-1;
	if((u+r)%2==1){
		cout<<-1;
		return 0;
	}
	else {
		if(u%2==1)
		{
			cout<<(u/2+r/2+1);

		}
		else
		{
			cout<<(u/2+r/2);
		}
	}
}