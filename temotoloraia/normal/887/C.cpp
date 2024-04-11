#include <bits/stdc++.h>
using namespace std;
int a[30],b[30],c[30];
main ()
{
    for (int i = 0; i < 100000; i++){}
	for (int i=1; i<=24; i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	
	int ok=0;
		for (int i = 0; i < 100000; i++){}
	for (int i=1; i<=24; i++)
		b[i]=a[i];
		
	b[2]=a[6];
	b[4]=a[8];
	b[6]=a[10];
	b[8]=a[12];
	b[10]=a[23];
	b[12]=a[21];
	b[23]=a[2];
	b[21]=a[4];
		for (int i = 0; i < 100000; i++){}
	for (int i=1; i<=21; i=i+4)
	{
		if (b[i]==b[i+1] && b[i]==b[i+2] && b[i]==b[i+3]) ok=1;
			else
		{
			ok=0;
			break;
		}
	}
	for (int i = 0; i < 100000; i++){}
	if (ok) 
	{
		cout<<"YES"<<endl;
		return 0;
	}
	
	for (int i=1; i<=24; i++)
		b[i]=a[i];
	
	b[1]=a[5];
	b[3]=a[7];
	b[5]=a[9];
	b[7]=a[11];
	b[9]=a[24];
	b[11]=a[22];
	b[24]=a[1];
	b[22]=a[3];
		for (int i = 0; i < 100000; i++){}
	for (int i=1; i<=21; i=i+4)
	{
		if (b[i]==b[i+1] && b[i]==b[i+2] && b[i]==b[i+3]) ok=1;
			else
		{
			ok=0;
			break;
		}
	}
	
	if (ok) 
	{
		cout<<"YES"<<endl;
		return 0;
	}

	for (int i=1; i<=24; i++)
		a[i]=c[i];
		
	/////////////////////
	
	for (int i=1; i<=24; i++)
		b[i]=a[i];
		
	b[5]=a[13];
	b[6]=a[14];
	b[17]=a[5];
	b[18]=a[6];
	b[21]=a[17];
	b[22]=a[18];
	b[13]=a[21];
	b[14]=a[22];
		
	for (int i=1; i<=21; i=i+4)
	{
		if (b[i]==b[i+1] && b[i]==b[i+2] && b[i]==b[i+3]) ok=1;
			else
		{
			ok=0;
			break;
		}
	}
	
	if (ok) 
	{
		cout<<"YES"<<endl;
		return 0;
	}
	
	for (int i=1; i<=24; i++)
		b[i]=a[i];
	
	b[7]=a[15];
	b[8]=a[16];
	b[19]=a[7];
	b[20]=a[8];
	b[23]=a[19];
	b[24]=a[20];
	b[15]=a[23];
	b[16]=a[24];
		
	for (int i=1; i<=21; i=i+4)
	{
		if (b[i]==b[i+1] && b[i]==b[i+2] && b[i]==b[i+3]) ok=1;
			else
		{
			ok=0;
			break;
		}
	}
	
	if (ok) 
	{
		cout<<"YES"<<endl;
		return 0;
	}
	
	for (int i=1; i<=24; i++)
		a[i]=c[i];
		
	/////////////////////
	
	for (int i=1; i<=24; i++)
		b[i]=a[i];
		
	b[17]=a[10];
	b[19]=a[9];
	b[3]=a[17];
	b[4]=a[19];
	b[16]=a[3];
	b[14]=a[4];
	b[9]=a[14];
	b[10]=a[16];
		
	for (int i=1; i<=21; i=i+4)
	{
		if (b[i]==b[i+1] && b[i]==b[i+2] && b[i]==b[i+3]) ok=1;
			else
		{
			ok=0;
			break;
		}
	}
	
	if (ok) 
	{
		cout<<"YES"<<endl;
		return 0;
	}
	
	for (int i=1; i<=24; i++)
		b[i]=a[i];
	
	b[11]=a[13];
	b[12]=a[15];
	b[18]=a[12];
	b[20]=a[11];
	b[1]=a[18];
	b[2]=a[20];
	b[13]=a[2];
	b[15]=a[1];
		
	for (int i=1; i<=21; i=i+4)
	{
		if (b[i]==b[i+1] && b[i]==b[i+2] && b[i]==b[i+3]) ok=1;
			else
		{
			ok=0;
			break;
		}
	}
	
	if (ok) 
	{
		cout<<"YES"<<endl;
		return 0;
	}

	cout<<"NO"<<endl;	
}