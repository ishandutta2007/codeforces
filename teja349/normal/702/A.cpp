#include<iostream>
using namespace std;
int main(){
	int n,a,b,t=1,s=1;
	cin>>n;
	
	cin>>a;
	for (int i = 1; i < n; ++i)
		{
			cin>>b;
			if(a<b){
				t++;
				if(s<t)
					s=t;
			}
			else
				t=1;
			a=b;


		}
		cout<<s<<endl;	
}