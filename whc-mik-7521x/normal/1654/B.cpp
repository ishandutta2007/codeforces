#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int pd[30],ans[N];
        memset(pd,0,sizeof pd);
        int n=s.length();
        for(int i=0;i<n;i++)ans[i]=1;
        for(int i=n-1;i>=0;i--){
			if(pd[s[i]-'a']!=0)ans[i]=0;
			pd[s[i]-'a']++;
		}
		for(int i=0;i<n;i++){
			if(ans[i]){
				for(int j=i;j<n;j++)putchar(s[j]);
				break;
			}
        }
		puts("");
    }
    return  0;
}