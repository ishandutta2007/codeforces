#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  std::string s;

 int k;
 cin >> s >> k;
   int n=s.length();
   if(n<=k){
	   cout<< (k+n)/2*2;
	   return 0;
   }
 int mt= (k+n)/2;
 int t=k;
 for(int l=k+1; l<=mt; l++){
	 int curr=k;
	 for(int pos=s.length()-1; pos>=l; pos--){
		 if(s[pos]==s[pos-l]) curr++;
		 else{
			 curr=0;
		 }
		 if(curr>=l) {
			 t=l;
			 continue;
		 }
	 }

 }
 cout<< 2*t;

 //cout << s << s.length() << s[2];
  return 0;
}