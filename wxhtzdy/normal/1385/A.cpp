#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;
	cin>>tt;
	while(tt--){
		int x,y,z;
		cin>>x>>y>>z;
		/*if(x>y)swap(x,y);
		if(x>z)swap(x,z);
		if(y>z)swap(y,z);*/
		if(x!=y&&x!=z&&y!=z){cout<<"NO\n";continue;}
		if((x==y&&x<z)||(x==z&&x<y)||(z==y&&y<x)){cout<<"NO\n";continue;}
		cout<<"YES\n";
		if(x==y){cout<<x<<" "<<z<<" "<<z<<endl;continue;}
		if(x==z){cout<<x<<" "<<y<<" "<<y<<endl;continue;}
		if(y==z){cout<<x<<" "<<x<<" "<<y<<endl;continue;}
	}
}