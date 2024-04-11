#include<iostream>
using namespace std;
int main(){
	int n,k,t,r,tot,sumk;
	cin>>n>>k>>t>>r>>tot>>sumk;
	int sumb= tot- sumk;
	 int l = sumk/k;
	 int j = sumk%k;
	 for (int i = 0; i < j; ++i)
	 {
	 	cout<<l+1<<" ";
	 }
	 for (int i = 0; i < k-j; ++i)
	 {
	 	cout<<l<<" ";
	 }
	 if((n-k)!=0){
	  l=sumb/(n-k);
	  j = sumb%(n-k);
	 for (int i = 0; i <j ; ++i)
	 {
	 	cout<<l+1<<" ";
	 }
	 for (int i = 0; i < n-k-j; ++i)
	 {
	 	cout<<l<<" ";
	 }
	 }
	
}