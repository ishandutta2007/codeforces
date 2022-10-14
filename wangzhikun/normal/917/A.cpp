//
//  main.cpp
//  Round 459
//
//  Created by  on 2018/7/25.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int ans = 0;
char S[5010];
int main() {
	cin>>S;
	int n = (int)strlen(S);
	for(int s = 0;s<n;s++){
		int cu = 0,pon = 0;
		for(int t = s;t<n;t++){
			if(S[t] == '(')cu+=1;
			if(S[t] == ')')cu-=1;
			if(S[t] == '?'){
				if(cu>0){
					cu-=1;
					pon+=1;
				}else{
					cu+=1;
				}
			}
			while(cu<0 && pon>0){pon-=1;cu+=2;}
			if(cu == 0){
				//cout<<s<<' '<<t<<endl;
				ans+=1;
			}
			if(cu<0){
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}