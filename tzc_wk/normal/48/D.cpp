#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int MAXN=1e5+100;
int n,num[MAXN],x[MAXN];
int max_num=0;
vector<int> pos[MAXN];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
		num[x[i]]++;
		max_num=max(max_num,x[i]);
		pos[x[i]].push_back(i);
	}
	int cur=0;
	while(num[1]!=0){
		int i=1;
		while(num[i]>0)	i++;
		i--; 
		for(int j=1;j<=i;j++)	num[j]--;
		cur++;
		for(int j=1;j<=i;j++){
			x[pos[j][0]]=cur;
			pos[j].erase(pos[j].begin());
		}
	}
	for(int i=2;i<=max_num;i++){
		if(num[i]){
			puts("-1\n");
			return 0;
		}
	}
	cout<<cur<<endl;
	for(int i=0;i<n;i++)	cout<<x[i]<<" "; 
	return 0;
}