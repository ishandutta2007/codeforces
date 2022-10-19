#include<bits/stdc++.h>
using namespace std;
const int N=100005;
priority_queue<long long,vector<long long>,greater<long long>>q;
long long t[N],v[N],sum[N];                            
int main()
{
    ios::sync_with_stdio(false);
	int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
	{
        cin>>t[i];
        sum[i]=t[i]+sum[i-1];
    }
    for(int i=1;i<=n;i++)
	{
        q.push(v[i]+sum[i-1]);                  
        long long ans=t[i]*q.size(); 
        while(!q.empty()&&q.top()<=sum[i])
        {
            ans+=q.top()-sum[i];
            q.pop();
        }
        cout<<ans<<' ';
    }
    cout<<endl;
    return 0;
}