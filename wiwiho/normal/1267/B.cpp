#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main(){
//	IOS;
	string str;
	cin >> str;
	int s=str.size(),cnt=1;
	if(s==1){
		cout << "0\n";
		return 0;
	}
	for(int i=1;i<s;i++){
		if(str[i]!=str[i-1]) cnt++;
	}
	if(cnt%2==0){
		cout << "0\n";
		return 0;
	}
	int ct=1;
	vector<int> num;
	vector<char> ch;
	for(int i=1;i<s;i++){
		if(str[i]!=str[i-1]){
			num.push_back(ct);
			ch.push_back(str[i-1]);
			ct=1;
			if(i==s-1){
				num.push_back(1);
				ch.push_back(str[s-1]);
			}
		}
		else if(i==s-1){
			num.push_back(ct+1);
			ch.push_back(str[s-1]);
		}
		else ct++;
	}
	if(num[cnt/2]<2){
		cout << "0\n";
		return 0;
	}
	for(int l=cnt/2-1,r=cnt/2+1;l>=0 && r<num.size();l--,r++){
		if(ch[l]==ch[r] && num[l]+num[r]>=3) continue;
		else{
			cout << "0\n";
			return 0;
		}
	}
	cout << num[cnt/2]+1 << '\n';
	return 0;
}