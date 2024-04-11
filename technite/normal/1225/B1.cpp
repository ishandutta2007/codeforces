#include<iostream>
#include<cstring>
#include<string>
#include<bits//stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;
int different(int A[],int n){
int res = 1; 
  
    for (int i = 1; i < n; i++) { 
        int j = 0; 
        for (j = 0; j < i; j++) 
            if (A[i] == A[j]) 
                break; 
  
        if (i == j) 
            res++; 
    } 
    return res; 
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,d;
		cin>>n>>k>>d;
		int A[n];
		int count,mincount=10000;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		
		for(int i=0;i<=n-d;i++)
		{
			int B[d]={0};
			for(int j=i;j<i+d;j++)
			{
				B[j-i]=A[j];
			}
			count=different(B,d);
			if(count==1) {
				mincount=count;
				break;
			}
			else
			{
				if(mincount>count) mincount=count;
			}	
			//cout<<mincount<<endl;

		}
		cout<<mincount<<endl;

	}
}