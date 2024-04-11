#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	char ch=getchar();
	ch=getchar();
	ch=getchar();
	int p=1,n=0,c[103],b[103],a[103],count = 1,num;
	a[0]=1;
	while(ch!='='){
		if(ch=='+'){
			a[count++]=1;
			p++;
		}
		else
		{
			a[count++]=0;
			n++;
		}
		ch=getchar();
		ch=getchar();
		ch=getchar();
		ch=getchar();
	}
	cin>>num;
	if((p-n*num <= num) && ( p*num-n >= num)){
		cout<<"Possible"<<endl;
		int s =num-p+n*num;
		for (int i = 0; i < p; ++i)
		{
			if(s==0){
				b[i]=1;
			}
			else if(s>num-1){
				b[i]=num;
				s-=num-1;
			}
			else{
				b[i]=1+s;
				s=0;
				
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(s==0)
			{		
				c[i]=num;
			}
			else if(s>num-1){
				c[i]=1;
				s-=num-1;

			}
			else
			{
				c[i]=num-s;
				s=0;
				
			}
		}
		cout<<b[0]<<" ";
		int j=1,k=0;
		for (int i = 1; i < count; ++i)
		{
			if(a[i]==1)
			{
				cout<<"+"<<" "<<b[j]<<" ";
				j++;
			}
			else
			{
				cout<<"-"<<" "<<c[k]<<" ";
					k++;
			}
		}
		cout<<"="<<" "<<num;
	}
	else{
		cout<<"Impossible"<<endl;
	}

}