#include<iostream>
using namespace std;
int main(){
	int n,t,a[100],s=0;
	cin>>n>>t;
	t=t-1;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	if(a[t]==1)
		s++;
	int x=t-1,y=t+1;
	while(x>=0 && y<=n-1){
		if(a[x]==1 && a[y]==1)
			s+=2;
		x--;
		y++;
	}
	if(x<0){
		while(y<=n-1){
			if(a[y] == 1){
				s++;
			}
			y++;
		}
	}
	else if(y=n){
		while(x>=0){
			if(a[x]==1){
				s++;
			}
			x--;
		}
	}
	cout<<s;
}