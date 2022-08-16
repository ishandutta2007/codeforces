#include<iostream>
using namespace std;
struct ad
{
	int x;
	int y;
};
int main(){
	int n;ad a[101],t;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		a[i].x=i+1;
		cin>>a[i].y;

	}
	for (int i = 0; i < n-1; ++i)
	{
		for (int i = 0; i < n-1; ++i)
		{
			if(a[i].y>a[i+1].y)
			{
				t.x=a[i].x;
				a[i].x=a[i+1].x;
				a[i+1].x=t.x;
				t.y=a[i].y;
				a[i].y=a[i+1].y;
				a[i+1].y=t.y;
			}

		}
	}
	int f=n-1,i=0;
	while(i<f){
		cout<<a[i].x<<" "<<a[f].x<<endl;
		i++;
		f--;
	}
	return 0;
}