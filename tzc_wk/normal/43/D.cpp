#include <iostream>
#include <cstdio>
#include <map>
#include <list>
#include <stack>
#include <ctime>
#include <time.h>
#include <fstream> 
#include <algorithm> 
#include <deque> 
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <memory>
#include <bitset>
#include <istream>
#include <ostream>
#include <iterator>
#include <complex>
using namespace std;
#define o(a)	cout<<a<<endl
int n,m;
int main(){ 
	cin>>n>>m;
	if(n*m%2||n==1&&m>2||m==1&&n>2){
    	o(1);o(n<<" "<<m<<" 1 1");
    	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cout<<i<<" "<<(i%2?j:m-j+1)<<endl;
    	o("1 1");
    	return 0;
	}
	o(0);o("1 1");
	if(n%2==0){
    	for(int i=1;i<=n;i++)for(int j=2;j<=m;j++)cout<<i<<" "<<(i%2?j:m-j+2)<<endl;
    	for(int i=n;i>=1;i--)o(i<<" 1");
	}
	else{
		for(int i=1;i<=m;i++)for(int j=2;j<=n;j++)cout<<(i%2?j:n-j+2)<<" "<<i<<endl;
    	for(int i=m;i>=1;i--)o("1 "<<i);
	}
	return 0;
}