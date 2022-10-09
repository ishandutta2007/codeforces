#include <iostream>

using namespace std;

int main(){
	unsigned h,w,x,y,t;
	cin>>h>>w;
	for(y=0; y<h; ++y){
		for(x=0; x<w; ++x){
			cin>>t;
			if((x^y)&1)
				cout<<"720720 ";
			else cout<<720720+t*t*t*t<<' ';
		}
		cout<<'\n';
	}
	return 0;
}