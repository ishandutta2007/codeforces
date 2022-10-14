//
//  main.cpp
//  CF WJH
//
//  Created by  on 2018/4/15.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>

using namespace std;

char a[5][5];

int main() {
	int ans = 0;
	for(int i=0;i<4;i++)cin>>a[i];
	for(int i = 0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[i][j] == '.'){
				a[i][j] = 'x';
				for(int cx = 0;cx<4;cx++){
					for(int cy = 0;cy<4;cy++){
						for(int dx = -1;dx<=1;dx++){
							for(int dy = -1;dy<=1;dy++){
								if(dx == 0 && dy == 0)continue;
								if(cx+2*dx<4&&cx+2*dx>=0&&cy+2*dy<4&&cy+2*dy>=0){
									if(a[cx][cy] == 'x' && a[cx+dx][cy+dy] == 'x'&&a[cx+2*dx][cy+2*dy] == 'x')ans = 1;
								}
							}
						}
					}
				}
				a[i][j] = '.';
			}
		}
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}