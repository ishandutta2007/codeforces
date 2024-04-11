//CF 898C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
map<string,int> M;
map<string,int>::iterator it;
vector<string> v[22],p;
string s;
bool issuf(string& a,string& b){
	int la,lb;
	la=a.length(),lb=b.length();
	if(la>lb)
		return 0;
	while(la){
		la--,lb--;
		if(a[la]!=b[lb])
			return 0;
	}
	return 1;
}
int unq(vector<string>& vv){
	sort(vv.begin(),vv.end());
	return unique(vv.begin(),vv.end())-vv.begin();
}
int main()
{
	int n,i,j,k,t;
	cin>>n;
	t=0;
	while(n--){
		cin>>s;
		if(M.find(s)==M.end())
			M[s]=t++;
		i=M[s];
		cin>>j;
		while(j--){
			cin>>s;
			v[i].push_back(s);
		}
	}
	cout<<t<<endl;
	for(it=M.begin();it!=M.end();it++){
		cout<<(*it).first<<' ';
		i=(*it).second;
		n=unq(v[i]);
		p.clear(),t=0;
		for(j=0;j<n;j=j+1){
			for(k=0;k<n;k=k+1)
				if(j!=k&&issuf(v[i][j],v[i][k]))
					break;
			if(k==n)
				p.push_back(v[i][j]),t++;
		}
		cout<<t;
		for(j=0;j<t;j=j+1)
			cout<<' '<<p[j];
		cout<<endl;
	}
	return 0;
}