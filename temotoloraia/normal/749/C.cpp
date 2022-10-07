#include <bits/stdc++.h>
using namespace std;
string s;
int fix[200005],sum,n,d,r,a,b;
int main()
{
	cin>>n>>s;
	for (int i=0;i<n;i++)
	if (s[i]=='D')a++;
	else b++;
	while (true){
		for (int i=0;i<n&&a&&b;i++)
		if (fix[i]==0){
			if (s[i]=='D' && r){
				fix[i]=1;
				a--;
				r--;
				continue;
			}
			if (s[i]=='R' && d){
				fix[i]=1;
				b--;
				d--;
				continue;
			}
			if (s[i]=='D')d++;
			else r++;
		}
		if (a==0){cout<<"R"<<endl;return 0;}
		if (b==0){cout<<"D"<<endl;return 0;}
	}
	return 0;
}