#include<bits/stdc++.h>
using namespace std;
int main(){
	string s[30]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
	string a[1000];
	int n,i,j,l=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    
	}
	for(i=0;i<n;i++)
	{
	    for(j=0;j<30;j++)
	    {
	    if(a[i]==s[j])
	    l++;
	}
	}
	cout<<l;
}