#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	char ch;int c=0,a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
	for (int i = 0; i < 19; ++i)
	{
		cout<<a[i]<<endl;
		fflush(stdout);
		ch=getchar();
		if(ch=='y'){
			c++;
			ch=getchar();
			ch=getchar();
			ch=getchar();
		}
		else{
			ch=getchar();
			ch=getchar();
		}
		if(c==2)
			break;
	}
	if(c<2)
		cout<<"prime";
	else
		cout<<"composite";
	return 0;
	
}