#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>d(n);
	for(int i=0;i<n;i++)
		cin>>d[i];
	sort(d.begin(),d.end());
	vector<long long>pref(n+1);
	for(int i=0;i<n;i++)
		pref[i+1]=pref[i]+d[i];
	vector<int>bal(n+2);
	int j=0;
	for(int k=1;k<=n;k++)
	{
		long long l=pref[n]-pref[n-k];
		long long r=(long long)k*(k-1);
		while(j<n&&d[j]<k)
			j++;
		int up=min(n-k,j);
		r+=pref[up]+(long long)k*((n-k)-up);
		int bound=d[n-k];
		long long diff=l-r;
		if(diff<=k&&diff<=bound)
		{
			bal[max(diff,0LL)]++;
			bal[bound+1]--; 
		}
		l-=d[n-k];
		r+=min(d[n-k],k);
		diff=r-l;
		if(diff>=bound+1)
		{
			bal[bound+1]++;
			bal[min(diff+1,n+1LL)]--;
		} 
	}
	vector<int>res;
	int b=0;
	for(int i=0;i<=n;i++)
	{
		b+=bal[i];
		if(b==n)
			if((pref[n]+i)%2==0)
				res.push_back(i);
	}
	if(res.empty())
		cout<<-1;
	else
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<' ';
	cout<<endl;
	return 0;
}