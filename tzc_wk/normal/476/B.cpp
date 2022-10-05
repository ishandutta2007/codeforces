#include <bits/stdc++.h>
using namespace std;
string s,t;
int a,b,cnt=0;
int main(){
	cout<<fixed<<setprecision(12);
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+')	a++;
		else if(s[i]=='-')	a--;
	}
	vector<int> pos;
	for(int i=0;i<t.size();i++){
		if(t[i]=='+')	b++,cnt++;
		else if(t[i]=='-')	b--,cnt++;
		else if(t[i]=='?')	pos.push_back(i);
	}
	int ret=0;
	double ans;
	int n=t.size()-cnt;
	for(int i=0;i<(1<<n);i++){
		int tmp=b;
		for(int j=0;j<n;j++){
			if(i>>j&1)	tmp++;
			else	tmp--;
		}
		if(tmp==a)	ret++;
	}
	ans=(ret*1.0)/(double)(1<<n);
	cout<<ans<<endl;
}
/*
++-+-
+-+-+

+-+-
+-??

+++
??-

+++--+-++
?????????

++++++++++
??????????
*/