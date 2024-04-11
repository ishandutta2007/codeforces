#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int p[N];
bool pos[N],val[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&p[i]);
		if(p[i]!=0){
			pos[i]=1;
			val[p[i]]=1;
		}
	}
	set<int> s1,s2,s3;
	for(int i=1;i<=n;i++){
		if(!pos[i] && !val[i])s3.insert(i);
		else if(!pos[i])s2.insert(i);
		else if(!val[i])s1.insert(i);
	}
	while(s1.size() || s2.size()){
		if(s3.size()){
			if(s1.size()){
				int i=*s1.begin();
				s1.erase(i);
				int j=*s3.begin();
				s3.erase(j);
				p[j]=i;
				s1.insert(j);
			}else if(s2.size()){
				int i=*s2.begin();
				s2.erase(i);
				int j=*s3.begin();
				s3.erase(j);
				p[i]=j;
				s2.insert(j);
			}
		}else{
			break;
		}
	}
	if(s3.size()){
		vector<int> vals(s3.begin(),s3.end());
        for(int i=0,j=(int)vals.size()-1;i<vals.size();j=i,i++)p[vals[i]]=vals[j];
	}
	if(s1.size()){
		vector<int> poss(s2.begin(),s2.end());
		vector<int> vals(s1.begin(),s1.end());
		for(int i=0;i<vals.size();i++)p[poss[i]]=vals[i];
	}
	for(int i=1;i<=n;i++)printf("%i%c",p[i],i==n?'\n':' ');
	return 0;
}