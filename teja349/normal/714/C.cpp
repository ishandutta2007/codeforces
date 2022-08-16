#include<iostream>
#include<stdio.h>
using namespace std;

int num(long long int n){
	int s=0,a=1;
	while(n>0){
		if((n%10)%2==1){
			s+=a;
		}
		a=a*2;
		n=n/10;

	}
	return s;
}

int main(){
	long long int t,n;char ch;
	int a[1000000]={0};
	cin>>t;
	while(t--){
		cin>>ch;
		if(ch=='+')
		{
			cin>>n;
			a[num(n)]++;
		}
		else if(ch=='-')
		{
			cin>>n;
			a[num(n)]--;
		}
		else{
			int s=0,p=1,i=1;
			char b[100]={0};
			ch=getchar();
			while(ch=='0'){
				ch=getchar();
			}
			//b[0]=1;
			while(ch!='\n'){
				b[i]= ch-48;
				i++;
				ch=getchar();
			}
			for (int j = i-1; j >=0;j--)
			{
				if(b[j]==1)
					s+=p;
				p*=2;
			}

			cout<<a[s]<<endl;
		}
	}

}