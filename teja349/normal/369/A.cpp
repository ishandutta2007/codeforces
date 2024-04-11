#include<iostream>
using namespace std;
int main(){
	int n,b,p;
	int x,sum=0;
	cin>>n>>b>>p;
	for (int i = 0; i < n; ++i)
	{	cin>>x;
		if (x==1)
		{
			b--;
		}
		else if(x==2){
			if(p>0){
				p--;
			}
			else{
				b--;
			}
		}
		if(b==-1){
			sum ++;
			b=0;
		}
	}
	cout<<sum;
}