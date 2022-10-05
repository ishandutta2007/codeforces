#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1,pair<int, int> p2)
{
    return p2.second<p1.second;
}
vector<pair<int,int> > k;
vector<pair<int,int> > c;
vector<pair<int,int> > ans; 
int main()
{
    int n,v;
    int t,p;
    cin>>n>>v;
    for(int i=0;i<n;i++)
	{
        cin>>t>>p;
        if(t==1)
		{
            k.push_back(make_pair(i+1,p));
        }
		else
		{
            c.push_back(make_pair(i+1,p));
        }
    }
    sort(k.begin(),k.end(),cmp);
    sort(c.begin(),c.end(),cmp);
    int cur=0;
    while(v>1&&cur<c.size())
	{
        ans.push_back(c[cur]);
        v-=2;
        cur++;
    }
    int last=ans.size()-1;
    int nowk=0;
    while(v>0&&nowk<k.size())
	{
        ans.push_back(k[nowk]);
        v-=1;
        nowk++;
    }
    for(;nowk<k.size()-1&&last>=0;nowk+=2)
	{
        if(k[nowk].second+k[nowk+1].second>ans[last].second)
		{
            ans.erase(ans.begin()+last);
            ans.push_back(k[nowk]);
            ans.push_back(k[nowk+1]);
            last--;
        }
    }
    if(last>=0&&nowk==k.size()-1)
	{
        if (k[nowk].second>ans[last].second)
		{
            ans.erase(ans.begin()+last);
            ans.push_back(k[nowk]);
            last--;
        }
    }
    if(ans.size()>0)
	{
        int tot=0;
        for(int i=0;i<ans.size();i++) tot+=ans[i].second;
        cout<<tot<<endl<<ans[0].first<<endl;
        for (int i=1;i<ans.size();i++) cout<<ans[i].first<<" ";
        cout<<endl;
    }
	else
	{
        cout<<"0"<<endl;
    }
    return 0;
}