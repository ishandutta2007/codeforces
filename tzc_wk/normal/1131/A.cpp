#include <bits/stdc++.h>
using namespace std;
int w1,w2,h1,h2;
int main(){
	cin>>w1>>w2>>h1>>h2;
	cout<<w2*2+2+w1+h2+1+h1+1+1+h2+(w1-h1-1)<<endl;
}