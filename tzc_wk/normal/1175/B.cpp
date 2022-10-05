#include <bits/stdc++.h>
using namespace std;
stack<long long> s;
#define SET_MAX 4294967295
long long n,x=0;
bool f=0;
int main(){
	cin>>n;s.push(1);
	while(n--){
		string S;
		cin>>S;
		if(S=="for"){
			long long t;cin>>t;
			if(s.top()>SET_MAX)	t=1;
			s.push(t*s.top());
		}
		else if(S=="end")	s.pop();
		else				x+=s.top();
		if(x>SET_MAX)	f=1;
	}
	if(f==1)	cout<<"OVERFLOW!!!"<<endl;
	else		cout<<x<<endl;
}