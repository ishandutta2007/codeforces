#include<iostream>
using namespace std;
int main(){
	unsigned long long int d,k,a,b,t,w=0;
	cin>>d>>k>>a>>b>>t;
	if(d<=k){
		cout<<d*a;
		return 0;
	}
	if((a*k+t)<b*k)
	{
		w=a*k+(d/k-1)*(a*k+t);
		if((d%k*a+t)<(d%k*b))
			w+=d%k*a+t;
		else
			w+=d%k*b;

	}
	else
		w=a*k+(d-k)*b;
	cout<<w<<endl;

}