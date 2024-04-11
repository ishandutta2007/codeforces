#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,t,k,h=0,hw=0;
	cin>>n>>t;
	char a[200000];
	char ch=getchar();
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];

	}
	for (int i = 1; i < n; ++i)
	{	
		 if(a[i]=='.')
		 	hw=1;

		if(a[i]>='5' && hw==1){
			k=i;

			h=1;
			break;

		}
	}

	int i=k;
	if(h==1){
	

	for (int j = 0 ; j <t;j++)
	{	

		if(a[i-1]!='.'&& a[i-1]=='4'&&(i-1)>=0){

			a[i-1]='5';
			if(hw==0)
				i=i-1;
			else{

				a[i]='0';
				i=i-1;
			}
		}
		else if(a[i-1]=='.'&&(i-2)>=0)
		{
			i=i-2;
			while(a[i]=='9' &&i>=0){
				a[i]='0';
				i--;
			}
			if(i==-1){
				cout<<1;
				break;
			}
			else{
				a[i]++;
				break;
			}

			

		}
		else if(i-1>=0)
		{	

			if(i-1==0)
			{	
				if(a[i-1]=='9')
				{
					a[i-1]='0';
					i--;
					cout<<'1';
					break;
				}
				else
				{
					a[i-1]++;
					a[i]='0';
					i--;
					break;
				}
			}
			else{

			a[i-1]++;
			a[i]='0';
			i--;
			break;
		}
			
		}
	}
	}
	else
	{
		i=n-1;
	}

	for (int j = 0; (j <=i)||h; ++j)
	{
		if(a[j]=='.')
		{
			h=0;

			if(j>=i)
				break;
			cout<<'.';	
		}
		else{
			if(j<=i)	
				cout<<a[j];
			else 
				cout<<'0';
		}
	}
}