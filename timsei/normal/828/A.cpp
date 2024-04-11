using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define F(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define ll long long
int n,a,b,c;
int t,ans;
int main() {
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) {
		cin>>t;
		if(t==1) {
			if(a) a--;
			else 
			{
				if(b) b--,c++;
				else
				{
					if(c) {
						c--;
					}
					else ans++;
				}
			}
			
		}
		else
		{
			if(b) b--;else ans+=2;
		}
	}
	cout<<ans<<endl;
}