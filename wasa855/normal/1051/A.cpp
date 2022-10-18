#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main()
{
	int T;
	cin>>T;
	string a;
	for(int iii=1;iii<=T;iii++)
	{
		cin>>a;
		int len=a.length();
		int sa=0,sA=0,s0=0;
		int la[105],lA[105],l0[105];
		for(int i=0;i<len;i++)
		{
			if(a[i]>='a'&&a[i]<='z')
			{
				la[sa++]=i;
			}
			if(a[i]>='A'&&a[i]<='Z')
			{
				lA[sA++]=i;
			}
			if(a[i]>='0'&&a[i]<='9')
			{
				l0[s0++]=i;
			}
		}
		if(sa!=0&&sA!=0&&s0!=0)
		{
			cout<<a<<endl;
		}
		else if(sa!=0&&sA==0&&s0==0)
		{
			a[0]='A';
			a[1]='0';
			cout<<a<<endl;
		}
		else if(sA!=0&&sa==0&&s0==0)
		{
			a[0]='a';
			a[1]='0';
			cout<<a<<endl;
		}
		else if(s0!=0&&sA==0&&sa==0)
		{
			a[0]='a';
			a[1]='A';
			cout<<a<<endl;
		}
		else if(s0==0&&sa!=0&&sA!=0)
		{
            if(sa>sA)
			{
				a[la[0]]='0';
			}
            else
			{
				a[lA[0]]='0';
			}
            cout<<a<<endl;
        }
		else if(sa==0&&s0!=0&&sA!=0)
		{
            if(s0>sA)
			{
				a[l0[0]]='a';
			}
            else
			{
				a[lA[0]]='a';
			}
            cout<<a<<endl;
        }
		else if(sA==0&&s0!=0&&sa!=0)
		{
            if(s0>sa)
			{
				a[l0[0]]='A';
			}
            else
			{
				a[la[0]]='A';
			}
            cout<<a<<endl;
        }
	}
	return 0;
}