#include <bits/stdc++.h> 

using namespace std; 
#define int long long 
const int maxn=3e5+5;
int nxt[maxn];
int pr[maxn];
vector <int> slv(vector <int> v,vector <char> s,int m)
{
	//cout<<m<<" m "<<endl;
	//cout<<v.size()<<" v.size() "<<endl;
	/*cout<<m<<" m "<<endl;
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<' '<<s[i]<<endl;
	}
	cout<<endl;*/
	int n=v.size();
	for(int i=0;i<v.size();++i) nxt[i]=(i+1); 
	for(int i=0;i<v.size();++i) pr[i]=(i-1);
	map <int,int> u;
	bool ok[v.size()];
	for(auto &h:ok) h=1;
	for(int i=0;nxt[i]<n;) 
	{
		if(!ok[i])
		{
			i=nxt[i];
			continue;
		}
		if(s[i]=='R' && s[nxt[i]]=='L')
		{
			ok[i]=0;ok[nxt[i]]=0;
			u[v[i]]=(v[nxt[i]]-v[i])/2; 
			u[v[nxt[i]]]=u[v[i]]; 
			pr[nxt[nxt[i]]]=pr[i];
			nxt[pr[i]]=nxt[nxt[i]]; 
            if(pr[i]!=(-1)) 
            {
            	i=pr[i];
            	continue;
            }
		}
		i=nxt[i];
	}
	vector <int> z1,z2;
	for(int i=0;i<n;++i)
	{
		if(ok[i])
		{
			if(s[i]=='L')
			{
				z1.push_back(v[i]);
			}
			else 
			{
				z2.push_back(v[i]);
			}
		}
	}
	//cout<<" tgrf "<<endl;
	for(int i=0;(i+1)<z1.size();i+=2)
	{
		int x=z1[i];int y=z1[i+1];
		u[x]=((x+y)/2);u[y]=u[x];
	}
	reverse(z2.begin(),z2.end());
	for(int i=0;(i+1)<z2.size();i+=2)
	{
		int x=z2[i];int y=z2[i+1];
		u[x]=((2*m-x-y)/2);u[y]=u[x];
	}
	if(z1.size()%2==1 && z2.size()%2==1)
	{
		int x=z1.back();int y=z2.back();
		u[x]=(2*m+x-y)/2;u[y]=u[x];
	}
	vector <int> ans;
	for(auto h:v)
	{
		if(u.count(h)) ans.push_back(u[h]);
		else ans.push_back(-1);
	}
	return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		//cout<<" tgrf "<<endl;
		int n,m;
		cin>>n>>m;
		int a[n];
		char b[n];
		for(int i=0;i<n;++i) cin>>a[i];
		for(int i=0;i<n;++i) cin>>b[i];
		vector <int> v0,v1;
	    vector <char> s0,s1;
		map <int,int> u;
		for(int i=0;i<n;++i) {if(a[i]%2==0) {v0.push_back(a[i]);s0.push_back(b[i]);} else {v1.push_back(a[i]);s1.push_back(b[i]);}}
		//for(auto h:v0) cout<<h<<' ';
		//cout<<" v0 "<<endl;
		vector <pair<int,int> > h0;for(int i=0;i<v0.size();++i) h0.push_back({v0[i],s0[i]}); 
	    sort(h0.begin(),h0.end());
	    for(int i=0;i<h0.size();++i) {v0[i]=h0[i].first;s0[i]=h0[i].second;}
	    vector <pair<int,int> > h1;for(int i=0;i<v1.size();++i) h1.push_back({v1[i],s1[i]}); 
	    sort(h1.begin(),h1.end());
	    for(int i=0;i<h1.size();++i) {v1[i]=h1[i].first;s1[i]=h1[i].second;}
		vector <int> z0=slv(v0,s0,m);vector <int> z1=slv(v1,s1,m); 
	    for(int i=0;i<v0.size();++i) u[v0[i]]=z0[i];
	    for(int i=0;i<v1.size();++i) u[v1[i]]=z1[i];
	    for(auto h:a) cout<<u[h]<<' ';
        cout<<endl;
	}
	return 0;
}