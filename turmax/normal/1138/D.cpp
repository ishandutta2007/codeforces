#include <bits/stdc++.h>

using namespace std;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    vector <int> pref=prefix_function(s2);
    int a=pref[s2.size()-1];
    int x1,x2;
    int v1,v2;
    int n1,n2;
    n1=0;
    n2=0;
    x1=0;
    x2=0;
    v1=0;
    v2=0;
    for(int i=0;i<s1.size();++i)
    {
        if(s1[i]=='1')
        {
            ++n1;
        }
        else
        {
            ++n2;
        }
    }
    for(int i=0;i<s2.size();++i)
    {
        if(s2[i]=='1')
        {
            ++v1;
        }
        else
        {
            ++v2;
        }
    }
    for(int i=a;i<s2.size();++i)
    {
        if(s2[i]=='1')
        {
            ++x1;
        }
        else
        {
            ++x2;
        }
    }
    string res;
    for(int i=0;i<s2.size() && n1>=0 && n2>=0;++i)
    {
        if(s2[i]=='1')
        {
            if(n1==0)
            {
                break;
            }
            n1--;
            res+=s2[i];
        }
        else
        {
            if(n2==0)
            {
                break;
            }
            n2--;
            res+=s2[i];
        }
    }
    int z=0;
    while(z==0)
    {
    for(int i=a;i<(s2.size()) && n1>=0 && n2>=0;++i)
    {
        if(s2[i]=='1')
        {
            if(n1==0)
            {
                z=1;
                break;
            }
            n1--;
            res+=s2[i];
        }
        else
        {
            if(n2==0)
            {
                z=1;
                break;
            }
            n2--;
            res+=s2[i];
        }
    }
    }
    if(n1>0)
    {
        for(int i=0;i<n1;++i)
        {
            res+='1';
        }
    }
    if(n2>0)
    {
        for(int i=0;i<n2;++i)
        {
            res+='0';
        }
    }
    cout<<res;
    return 0;
}