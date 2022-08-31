#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
	int n,m,s=0,sum=0;
	cin>>n>>m;
	int a[3000],b[3000]={0};
	vector<pair<int,int> > v;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i]<=m){
			b[a[i]]++;
		}
	}
	int reqd=n/m;
	cout<<n/m<< " ";
	for (int i = 1; i <= m; ++i)
	{
		if(b[i]<reqd)
			s+=reqd-b[i];
		if(b[i]>reqd)
			sum+=b[i]-reqd;
	}
	//cout<<s<<sum;
	cout<<s<<endl;
	int ans=s;
	for (int i = 1; i <=m; ++i)
	{
		v.push_back(make_pair(b[i],i));
	}
	sort(v.begin(),v.begin()+m);
	vector<pair<int,int> >::iterator it,it1;
	it =  v.begin();
	it1 = v.end();
	it1--;
	//cout<<it->second;
	for (int i = 0; i < n && ans; ++i)
	{
		if(a[i]>m){
			it->first++;
			a[i]=it->second;

			ans--;

			if(it->first==reqd)
				it++;
		}


	}

		//cout<<it->second;
		for (int j = 0; j < n && ans; ++j)
		{
			for (int i = 0; i < n && ans; ++i)
		{
			
			if(a[i]==it1->second){
				//cout<<ans<<"hiii";
				ans--;
				//cout<<ans<<"byee";
				it1->first--;
			if(it1->first==reqd)
				it1--;
			it->first++;
			a[i]=it->second;
			
			if(it->first==reqd)
				it++;
			}

			if(ans==0){{
				//cout<<"mee";
				break;

			}
			}
		}
		if(ans==0)
			break;
		}
		
	

	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}

}