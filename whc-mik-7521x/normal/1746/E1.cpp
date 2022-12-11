#include<bits/stdc++.h>
using namespace std;
int n;
int get(){
	string s;
	cin>>s;
	return s=="YES";
}
void solve(vector<int>vec){
    if((int)vec.size()<3){
		cout<<"! "<<vec[0]<<endl;
		string s;
		cin>>s;
		if(s==":)")return;
		cout<<"! "<<vec[1]<<endl;
		return;
	}
	else if(vec.size()==3u){
		int pd[4];
		cout<<"? 1 "<<vec[0]<<endl;
		pd[0]=get();
		cout<<"? 1 "<<vec[1]<<endl;
		pd[1]=get();
		cout<<"? 1 "<<vec[1]<<endl;
		pd[2]=get();
		cout<<"? 1 "<<vec[0]<<endl;
		pd[3]=get();
		if(pd[1]&&pd[2])return solve({vec[1]});
		else if(!pd[1]&&!pd[2])return solve({vec[0],vec[2]});
		else if((pd[0]&&pd[1])||(pd[2]&&pd[3]))return solve({vec[0],vec[1]});
		else if((pd[0]&&!pd[1])||(!pd[2]&&pd[3]))return solve({vec[0],vec[2]});
		else return solve({vec[1],vec[2]});
	}
	else{
		vector<int>query[2];
		for(int i=0;i<(int)vec.size();i++){
			if(i&1)query[0].push_back(vec[i]);
			if(i&2)query[1].push_back(vec[i]);
		}
		int pd[2];
		for(int i=0;i<2;i++){
			cout<<"? "<<query[i].size();
			for(auto u: query[i])cout<<' '<<u;
			cout<<endl;
			pd[i]=get();
		}
		vector<int>nvec;
		for(int i=0;i<(int)vec.size();i++){
			if((!(i&1)^pd[0])||(!(i&2)^pd[1]))nvec.push_back(vec[i]);
		}
		return solve(nvec);
	}
}
int main(){
	scanf("%d",&n);
	vector<int>vec(n);
	for(int i=0;i<n;i++)vec[i]=i+1;
	solve(vec);
	return 0;
}