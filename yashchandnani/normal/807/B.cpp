#include <bits/stdc++.h>
using namespace std;

int main(){
	int yolo;
	int p,x,y;
	cin>>p>>x>>y;
	p-=26;
	int t=x;
	int a[475]={0};
	while(t>=y){
		t-=50;
	}
	t+=50;
	t/=50;
	t%=475;
	int t2=x;
	t2/=50;
	t2%=475;
	if (t2<t)
	{
		t2+=475;
	}

		for (int m = t; m <=t2; ++m)
		{	
			int i=m%475;
			for (int j = 0; j < 25; ++j)
			{
				
				i=i*96+42;
				i%=475;
				a[i]=1;
			}
		}

	if (a[p])
	{
		cout<<0<<endl;
	}
	else{
		int x=1;
		while(1){
			t2++;
			t2%=475;
			int i=t2;
			for (int j = 0; j < 25; ++j)
			{
				
				i=i*96+42;
				i%=475;
				a[i]=x;
			}
			t2++;
			t2%=475;
			i=t2;
			for (int j = 0; j < 25; ++j)
			{
				
				i=i*96+42;
				i%=475;
				a[i]=x;
			}
			if (a[p])
			{
				cout<<x<<endl;
				return 0;
			}
			x++;
		}


	}
	return 0;
}