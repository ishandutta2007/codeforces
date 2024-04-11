#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool arePermutation(string str1, string str2) 
{ 
    int n1 = str1.length(); 
    int n2 = str2.length();   
    sort(str1.begin(), str1.end()); 
    sort(str2.begin(), str2.end());  
    for (int i = 0; i < n1;  i++) {
       if (str1[i] != str2[i]) {
         return false; 
       }
    }
  
    return true; 
}    
int main()
{
	long int n;
	cin>>n;
	while(n--){
	string p,h;
	cin>>p;
	cin>>h;
	int t=0;
	if(h.size()>=p.size()){
	for(int i=0;i<=h.size()-p.size();i++)
	{
		if(arePermutation(p,h.substr(i,p.size()))) 
			{
				cout<<"YES"<<endl;

				t=1;
				break;
			}	
	}
	if(t==0) cout<<"NO"<<endl;
	}	
	else cout<<"NO"<<endl;
}
}