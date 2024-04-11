//
//  main.cpp
//  Round 480
//
//  Created by  on 2018/5/11.
//  Copyright  2018 . All rights reserved.
//

#include <iomanip>
#include <vector>
#include <cstring>
#include <iostream>


using namespace std;

int n,cnt[30];
char s[10010];
vector<int> r[30];

int main() {
	cin>>s;
	n = strlen(s);
	for(int i=0;i<n;i++)r[s[i]-'a'].push_back(i);
	int ans = 0;
	for(int i=0;i<26;i++){
		int cmax = 0,cc;
		for(int j=0;j<n;j++){
			cc = 0;
			memset(cnt,0,sizeof(cnt));
			for(int k = 0;k<r[i].size();k++){
				cnt[s[(j+r[i][k])%n]-'a']++;
			}
			for(int k=0;k<26;k++)if(cnt[k] == 1)cc+=1;
			cmax = max(cmax,cc);
		}
		ans+=cmax;
	}
	cout<<fixed<<setprecision(15)<<(double)ans/n<<endl;
	return 0;
}