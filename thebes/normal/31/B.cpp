#include <bits/stdc++.h>
using namespace std;

int n, cnt, i, last=-1, lol;
string s, t;

int main(){
	cin >> s; n=s.size();
	for(i=0;i<n;i++){
		if(s[i]=='@'){
                lol = 1;
			if((cnt<2&&last!=-1)||(cnt<1&&last==-1)){
				printf("No solution\n");
				return 0;
			}
			cnt=0; last=i;
		}
		else cnt++;
	}
	if(cnt<1||(!lol)){
        printf("No solution\n");
        return 0;
	}
	last = 1<<30;
	for(i=n-1;i>=0;i--){
        if(s[i]=='@'){
            if(last != 1<<30){
                s.insert(i+2,",");
            }
            last = i;
        }
	}
	printf("%s\n",s.c_str());
	return 0;
}