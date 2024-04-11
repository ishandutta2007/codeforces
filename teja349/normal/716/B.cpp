#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a[123456],b[400]={0},s=0,i;
	char ch=getchar();

	for ( i = 0; i < 26 && ch!='\n'; ++i)
	{
		 
		a[i]=ch;
		b[ch-63]++;
		if(ch-63 ==0)
			s++;
		else
		{
			if(b[ch-63]==1)
				s++;
		}
		ch= getchar();

	}
	
	//cout<<s<<endl;	
	if(s == 26)
	{	
		
		for ( i = 0; i < 26; ++i)
		{
			if(a[i]-63!=0)
				cout<<(char)a[i];
			else {
				for (int j = 0; j < 26; ++j)
				{
					if(b[65+j-63]==0){
						b[65+j-63]++;
						cout<<(char)(j+65);
						break;
					}
					
				}
			}
		}
		while(ch!='\n'){
			if(ch!='?')
				cout<<ch;
			else
				cout<<'M';
			ch=getchar();
		}
		return 0;
	}
	
		int h=0;	
	for ( i = 26;ch!='\n'; ++i)
	{
		
		a[i]=ch;
		b[ch-63]++;
		if(ch-63 ==0)
			s++;
		else
		{
			if(b[ch-63]==1)
				s++;
		}
		if(a[i-26]-63==0)
			s--;
		else{
			if(b[a[i-26]-63]==1){
				
				s--;
			}
			
		}
		b[a[i-26]-63]--;
		if(s==26){
			 h = 1;
			 //cout<<"Hii";
			break;

			
		}
		ch= getchar();
	}
	int m=i;
	m++;
	//cout<<b['A'-63]<<endl;
	if(h==0){
		cout<<-1;
		return 0;
	}
	else{
		for (int i = 0; i < m-26; ++i)
		{
			if(a[i]-63!=0)
				cout<<(char)a[i];
			else
				cout<<'M';
		}
		for (int i = m-26; i < m; ++i)
		{
			if(a[i]-63!=0)
				cout<<(char)a[i];
			else {
				for (int j =0; j < 26; ++j)
				{
					if(b[65+j-63]==0){
						b[65+j-63]++;
						cout<<(char)(j+65);
						break;
					}
					
				}
			}
		}
		ch=getchar();
		while(ch!='\n'){
			if(ch=='?')
				cout<<'M';
			else
				cout<<ch;
			ch=getchar();
		}
		return 0;
	}



}