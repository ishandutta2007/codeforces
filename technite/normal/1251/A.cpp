#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26; 
void sortString(string &str) 
{ 
    
    int charCount[MAX_CHAR] = {0}; 
      
    for (int i=0; i<str.length(); i++) 
       charCount[str[i]-'a']++;     
      
    for(int j=0;j<26;j++)
    {
    	if(charCount[j]!=0)cout<<(char)('a'+j);
    	
    } 
    
} 

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s,t;
		cin>>s;
		int j=0;
		
		for(int i=0;i<s.size();i)
		{
			
			char c=s[i];
			int count=1;

			while(i>=0)
			{
			if(i!=s.size()-1)
			{	 
				if(s[j+1]!=c)
				{
					j++;

					break;
				}
				
				j++;
				count++;
			}
			else
			{
				if(s[i]!=s[i-1])
				{
					t.append(s.substr(i,1));
					j++;
					count++;
										
				}
				else
				{
					count++;
					
					
				}
				break;
			}	
			}
			if (count%2==1){
				t.append(s.substr(i,1));
			}
			i=j;
			
		}
		
		
		sortString(t);
		cout<<endl;
		
		
}
}