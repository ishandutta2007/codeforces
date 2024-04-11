#include<iostream>
#include<cstdio>
using namespace std;
int a[4],b[4];
char c;
int main()
{
	int i;
	i=0;
	while(cin>>c){
		if(c=='!')
			b[i%4]++;
		if(c=='R')
			a[0]=i%4;
		if(c=='B')
			a[1]=i%4;
		if(c=='Y')
			a[2]=i%4;
		if(c=='G')
			a[3]=i%4;
		i=i+1;
		//if(c=='p')
		//	break;
	}
	for(i=0;i<3;i=i+1)
		cout<<b[a[i]]<<' ';
	cout<<b[a[3]]<<endl;
	return 0;
}