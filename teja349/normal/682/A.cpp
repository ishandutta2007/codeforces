#include<iostream>
using namespace std;
 int main(){
	long long int n,m,a,b,p,q,v=0,w=0,s=0;
	cin>>n>>m;
	a=n/5;
	b=n%5;
	p=m/5;
	q=m%5;
	for (int i = 0; i < 5; ++i)
	{
		if(i<=b){
			v=a+1;
		}
		else{
			v=a;
		}


		if(((5-i)%5) <= q){
			w=p+1;
			
		}
		else{
			w=p;
		}
		s+=v*w;
		
	}

	cout<<s-a-p-1;
}