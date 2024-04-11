#include <bits/stdc++.h> 

using namespace std;
#define int long long 
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		map <int,vector <int> > r;
		vector <int> keys;
		for(int i=0;i<n;++i) {cin>>a[i];
			if(!r.count(a[i])) 
				{keys.push_back(a[i]);r[a[i]]={i};}
			else 
				{r[a[i]].push_back(i);}
           }
           int res=0;
          for(auto h:keys)
          {
          	vector <int> v=r[h];
          	int sum=0;
          	int ans=0;
          	for(int i=0;i<v.size();++i) 
          	{
                ans+=((n-v[i])*sum);
          		sum+=(v[i]+1);
          	}
          	res+=ans;
          }
          cout<<res<<endl;
	}
	return 0;
}