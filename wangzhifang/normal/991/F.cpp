#include <string>
#include <unordered_map>
using namespace std;
unordered_map <long long,string> mp;
int main(){
	long long n;
	scanf("%lld",&n);
	for(register long long i=2;i*i<=n;++i)
		for(register long long j=i*i,k=2;j<=n;j*=i,++k){
			string tmp=to_string(i)+"^"+to_string(k);
			if(!mp.count(j))
				mp[j]=to_string(j);
			if(tmp.size()<mp[j].size())
				mp[j]=tmp;
		}
	string ans=to_string(n);
	for(auto x:mp){
		string tmp="";
		long long a=n/x.first,b=n%x.first;
		if(a>1)
			tmp=(mp.count(a)?mp[a]:to_string(a))+"*";
		tmp+=x.second;
		if(b)
			tmp+="+"+(mp.count(b)?mp[b]:to_string(b));
			if(tmp.size()<ans.size())
				ans=tmp; 
	}
	printf(ans.c_str());
}