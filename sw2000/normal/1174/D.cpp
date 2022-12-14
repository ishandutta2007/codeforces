#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
	int n,x,cnt=0,maxn=1;
	set<int>s;
	vector<int>ans;

	cin>>n>>x;
	for(int i=0;i<n;i++)maxn*=2;

	if(x>=maxn)
    {
        cout<<maxn-1<<endl;
        for(int i=1;i<maxn;i++)
            printf("%d ",i^(i-1));
        return 0;
    }

	s.insert(x);
	while(1)
    {
        while(s.find(++cnt)!=s.end());
        if(cnt==maxn)break;
        s.insert(cnt^x);
        ans.push_back(cnt);
    }

	int len=ans.size();
	for(int i=len-1;i>0;i--)
        ans[i]^=ans[i-1];

    cout<<len<<endl;
    for(int i=0;i<len;i++)
        printf("%d ",ans[i]);
	return 0;
}