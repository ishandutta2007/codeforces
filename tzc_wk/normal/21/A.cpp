#include <cstdio>  
#include <string>
#include <cstring>  
#include <iostream>  
using namespace std;  
#define Giveup {cout<<"NO"<<endl;return 0;}
char str[101]; 
bool judge(char c)
{ return (c=='_'||islower(c)||isdigit(c)||isupper(c)); }
 
int main()  
{  
    int cnt=0;  
    int count=0;
    int type=0; 
    cin>>str;
		type=0;   
    	int len=strlen(str);      
    	for(int i=0;i<len;i++)  
    	{  
    	    char c=str[i];  
    	    if(c=='@')  
    	    {  
    	        if(type==1) Giveup
    	        type=1;  
    	        if(cnt<1||cnt>16) Giveup;
    	        cnt=0;  
    	    }  
    	    else if(c=='/')  
    	    {  
    	        if(type==2) Giveup
    	        type=2;  
   	        	if(cnt<1||cnt>16) Giveup
            	if(count<1||count>32) Giveup
            	cnt=0;  
        	}  
        	else if(c=='.')  
        	{  
        	    if(type!=1) Giveup
        	    if(cnt<1||cnt>16) Giveup
        	    cnt=0;  
        	}  
        	else if(c>127||c<33) Giveup
        	else if(type==0) 
        	{  
        	    if(judge(c))   
        	    {  
        	        cnt++;  
        	        continue;  
        	    }  
        	    else Giveup
        	}  
        	else if(type==1)  
        	{  
        	    if(judge(c))   
        	    {  
        	        cnt++;  
        	        count++;  
        	        continue;     
        	    }  
        	    else Giveup
        	}  
        	else if(type==2)  
        	{  
        	    if(judge(c))  
        	    {  
        	        cnt++;  
        	        continue;  
        	    }   
        	    else Giveup
        	}  
    	}  	
    	if(cnt<0||cnt>16) Giveup
    	if(type>=1&&cnt>0) cout<<"YES"<<endl;
    	else Giveup
}