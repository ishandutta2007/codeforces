#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,mx=0,coun=0,c=0,d=0;
		cin>>n;
		vector<long long> a(n),b(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
			if(a[i]>mx) mx=a[i];
		}
		sort(a.begin(),a.begin()+mx);
		sort(a.begin()+mx,a.end());
		sort(b.begin(),b.begin()+n-mx);
		sort(b.begin()+n-mx,b.end());
		//for(int i=0;i<n;i++){cout<<a[i]<<" ";}
		
		//cout<<endl;
		//for(int i=0;i<n;i++){cout<<b[i]<<" ";}
		//cout<<endl;
		
		c=1;
		for(int i=0;i<mx;i++)
		{
			if(a[i]!=i+1) {c=0;break;}
		}
		if(c==1)
		{
			for(int i=mx;i<n;i++)
			{
				if(a[i]!=i-mx+1) {c=0; break;}
			}
		}
		if(c==1) {coun++;}
		d=1;
		for(int i=0;i<n-mx;i++)
		{
			if(b[i]!=i+1) {d=0;break;}
		}
		if(d==1)
		{
			for(int i=n-mx;i<n;i++)
			{
				if(b[i]!=i+mx-n+1) {d=0; break;}
			}
		}
		if(n-mx!=mx){
		if(d==1) coun++;}
		cout<<coun<<endl;
		if(c==1) cout<<mx<<" "<<n-mx<<endl;
		if(d==1&&n-mx!=mx) cout<<n-mx<<" "<<mx<<endl;
		
		
	}
}