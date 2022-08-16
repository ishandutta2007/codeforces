#include<iostream>
using namespace std;
int main(){
	long long int n,a[100001]={0},b[100001]={0},m;
	long long int x,y,p=0,q=0,r=0;
	cin>>n>>m;
	for (long long int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		if(a[x]==0){
			a[x]=1;
			
			r+=n-q;
			p++;
		}
		if(b[y]==0){
			b[y]=1;
			r+=n-p;
			q++;
		}
		
		cout<<n*n-r<<" ";
	}


}