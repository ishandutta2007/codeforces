#include <bits/stdc++.h>
using namespace std;

string s; int lo, hi;
bool check(int k){
	int a[26], b[26], l=0, r, ret=1;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for(r=0;r<(signed)s.size();r++){
		a[s[r]-'a']++;
		if(r-l+1 > k) a[s[l++]-'a']--;
		if(r-l+1 >= k){
			for(int i=0;i<26;i++){
				if(!a[i]) b[i] = 1;
			}
		}
	}
	for(int i=0;i<26;i++)
		ret = min(ret, b[i]);
	return !ret;
}

int main(){
	getline(cin, s);
	lo = 1; hi = s.size();
	while(lo != hi){
		int mid = (lo+hi)/2;
		if(check(mid)) hi = mid;
		else lo = mid+1;
	}
	printf("%d\n",lo);
	return 0;
}