#include<bits/stdc++.h>
using namespace std;

char s[10005];

int main(){
    cin>>s;
	cout<<s;
	reverse(s,s+strlen(s));
	cout<<s;
    return 0;
}