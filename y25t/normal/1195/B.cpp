#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define ld long double

ld n,k;

int main(){
	cin>>n>>k;
	cout<<(long long)(n-0.5*(sqrt(9+8*(n+k))-3));
}