#include<bits/stdc++.h>
using namespace std;
long long n,d,a,cnt=0;
vector<int> v;
char c;
int main() {
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>c>>a;
		if(c=='+'){
			/*sort(v.begin(),v.end());
			for(int r:v){
				if(r<=d)d-=r;
				else cnt++;
			}
			v.clear();*/
			d+=a;
		}
		else {
			if(d>=a){d-=a;}
			else cnt++;
		} 
		//v.push_back(a);	
	}
	/*sort(v.begin(),v.end());
	for(int r:v){
		if(r<=d)d-=r;
		else cnt++;
	}*/
	cout<<d<<" "<<cnt;
}