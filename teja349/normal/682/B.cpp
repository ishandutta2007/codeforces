#include<iostream>
#include<stdlib.h>
using namespace std;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(){
	int n;
	cin>>n;
	int a[100000];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	qsort(a,n,sizeof(int),cmpfunc);
	for (int i = 0; i < n; ++i)
	{
		a[i]=a[i]-(i+1);
	}
	qsort(a,n,sizeof(int),cmpfunc);
	
	if(n+a[0]>n)
		cout<<n+1;
	else
		cout<<n+a[0]+1;

}