#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
	int a[5],sum=0,c=0,max=0;
	for (int i = 0; i < 5; ++i)
	{
		cin>>a[i];
		sum+=a[i];

	}
	qsort(a,5,sizeof(int),cmpfunc);
	for(int i=4; i >0;i--){
		if(a[i] == a[i-1])
		{

			if(c==0){


			if(max<a[i]+a[i-1])
				max=a[i]+a[i-1];
			c++;
		}
		else if(c==1){
			if(max<a[i-1]+a[i]+a[i+1])
				max=a[i+1]+a[i]+a[i-1];
			c=0;
		}
		
		}
		else
			c=0;

	}
	cout<<sum-max;
}