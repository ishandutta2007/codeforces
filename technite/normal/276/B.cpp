#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int even=0,odd=0;
	map<char,int> m;
	for(char x:s) {
	    m[x]++;
	    //cout<<x;
	    //cout<<m[x]<<'d';
	}
	for(auto i=m.begin();i!=m.end();i++)
	{
	 int t=i->second;
	 if(t%2==0)
	 {
	     //cout<<m[x];
	 	even++;
	 }	
	 else odd++;
	//cout<<odd;
	} 	
	if(odd>1){
	if(odd%2==0) cout<<"Second";
	 else cout<<"First";
	}
	else cout<<"First";
}