#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string s2;
	vector<size_t> a[n];
	a[0].push_back(0);
	for (int i = 1; i < n; ++i)
	{
		cin>>s2;
		s2=s2+s2;
		size_t j=s2.find(s,0);
		if (j==string::npos)
		{
			cout<<-1;
			return 0;
		}
		while(j != string::npos)
	    {
	        a[i].push_back(j);
	        j = s2.find(s, j+1);
	    	
	    }
		
	}

	int min=3000;
	for (int i = 0; i < s.size(); ++i)
	{
		int t=-(i*n);
		for (int j = 0; j < n; ++j)
		{
			t+=a[j][0];
			if (a[j][0]==i)
			{
				a[j][0]+=s.size();
				sort(a[j].begin(),a[j].end());
			}
		}
		if (t<min)
		{
			min=t;
		}
	}
	cout<<min;
	return 0;
}