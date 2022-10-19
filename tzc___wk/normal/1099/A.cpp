#include <bits/stdc++.h>
using namespace std;
int w,h,d1,d2,u1,u2; 
int main(){
	cin>>w>>h>>d1>>d2>>u1>>u2;
	int curw=w;
	for(int i=h;i>0;i--){
		curw+=i;
		if(i==d2)	curw-=d1;
		else if(i==u2)	curw-=u1;
		if(curw<0)	curw=0;
	}
	cout<<curw<<endl;
	return 0;
}