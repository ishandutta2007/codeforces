#include<bits/stdc++.h>
 
using namespace std;
 
int n;
string s;
vector<int> vec;
long long ans=0;
int main(){
	cin>>s;
	n=s.size();
	int sum=0,tmp=0;
	for (int i=0;i<n;++i){
		if (s[i]=='v') tmp++;
		if (s[i]=='o'){
			sum+=max(tmp-1,0);
			tmp=0;
			vec.push_back(sum);
		}
	}
	sum+=max(tmp-1,0);
	for (auto c:vec){
		ans+=1LL*(sum-c)*c;
	}
	cout<<ans<<endl;
	return 0;
}