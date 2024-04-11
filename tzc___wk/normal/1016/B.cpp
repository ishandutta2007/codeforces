#include <iostream>
#include <string>
using namespace std;
int n,m,q;
string s,t;
int l,r;
int x[10100],ans[10100];
int main()
{
    cin>>n>>m>>q;
    cin>>s>>t;
	int k=0;
    for(int i=0;i<n;i++)
	{
        if(s[i]==t[0])
		{
		    int cnt=0;
            for(int j=0;j<m;j++)
			{
                if(s[i+j]==t[j]) cnt++;
                else break;
            }
            if(cnt==m) k+=1;
        }
    	x[i+1]=k;
	}
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        r=r-m+1;
        if(r<l) cout<<0<<endl;
        else cout<<x[r]-x[l-1]<<endl;
    }
    return 0;
}