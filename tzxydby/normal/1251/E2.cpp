#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m[N];
long long p[N];
vector<int>v[N];
int main()
{
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
	{
        cin>>n;
        for(int i=0;i<n;i++)
			v[i].clear();
        for(int i=1;i<=n;i++)
		{
            cin>>m[i]>>p[i];
            v[m[i]].push_back(p[i]);
        }
		priority_queue<long long,vector<long long>,greater<long long>>s;
	    int pre=n,cnt=0;
	    long long ans=0;
	    for(int i=n-1;i>=0;i--)
		{
	        pre-=v[i].size();
	        for(int j=0;j<v[i].size();j++)
	            s.push(v[i][j]);
	        int x=i-pre;
	        while(cnt<x)
			{
	            ans+=s.top();
	            s.pop();
	            cnt++;
	        }
	    }
	    cout<<ans<<endl;
    }
    return 0;
}