#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t; cin >> t;
	while(t--) 
	{
		int n, k, ans = 0; cin >> n >> k;
		string S; cin >> S;
		map<char,int> T[k];
		for(int i=0;i<n;i++)
			T[min(i%k,k-(i%k)-1)][S[i]]++;
		for(int i=0;i<k;i++)
		{
			int x=0, s=0;
			for(auto p : T[i]) 
			{
				x=max(x, p.second);
				s+=p.second;
			}
			ans+=s-x;
		}
		cout <<ans<<endl;
	
	}
	return 0;
	
}