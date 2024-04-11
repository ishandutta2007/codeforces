#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int type1[30]={0},type2[30]={0};
    for(int i=0;i<n;i++)
    {
        type1[a[i]-'a']++;
        type2[b[i]-'a']++;
    }
    for(int i=0;i<30;i++)
    {
    	if(type1[i]!=type2[i])
    	{
    		cout<<"-1"<<endl;
    		return 0;
		}
	}
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(b[i]==a[j])
            {
                for(int k=j;k>i;k--)
                {
                    swap(a[k],a[k-1]);
                    cnt++;
                    v.push_back(k-1+1);
                }
                break;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<v.size();i++)printf("%d ",v[i]);
}