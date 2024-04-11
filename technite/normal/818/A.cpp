#include<iostream>
using namespace std;
int main()
{
	long long int n,k;
	cin >> n>>k;
	long long int t = n/2;
	cout << t/(k+1) <<" "<< t/(k+1)*k<<" "<< n-t/(k+1)-t/(k+1)*k;
 }