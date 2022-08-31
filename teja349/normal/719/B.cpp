#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ro=0,re=0,bo=0,be=0;
	for (int i = 0; i < n; ++i)
	{
		if(s.at(i)=='r'){
			if(i%2==0)
				re++;
			else ro++;
		}
		else{
			if(i%2==0)
				be++;
			else 
				bo++;
		}
	}
	int a=min(re,bo)+abs(re-bo);
	int b=min(ro,be)+abs(be-ro);
	cout<<min(a,b);
}