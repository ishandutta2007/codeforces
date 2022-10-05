#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-7;
double a[100001];
int n,b[100001];
bool mark[100001];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=floor(a[i]);
		if(a[i]-b[i]<EPS)	mark[i]=true;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=b[i];
	}
	sum=-sum;
	for(int i=0;i<n;i++){
		if(sum&&!mark[i]){
			cout<<b[i]+1<<"\n";
			sum--;
		}
		else	cout<<b[i]<<"\n";
	}
	return 0;
}