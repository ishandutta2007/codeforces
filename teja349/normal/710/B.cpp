#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector< long long int > a(300002);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.begin()+n);
	int t=(n+1)/2;
	cout<<a[t-1]<<endl;

}