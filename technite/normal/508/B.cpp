#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length()-1;
	int ind=n;
	for(int i=0;i<=n;i++){
		if(s[i]%2==0){
			ind=i;
			if(s[n]>s[i])
				break;
		}
	}
	if(ind==n)
		cout<<"-1";
	else
		{
			swap(s[ind],s[n]);
			cout<<s;
		}
}